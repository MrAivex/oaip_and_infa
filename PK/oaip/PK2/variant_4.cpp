#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <cstring>

class FoodItem {
protected:
    std::string name, expirationDate;
    double weight;
    std::vector<std::string> suppliers;
    
public:
    FoodItem(const std::string& n="", const std::string& ed="", double w=0.0) 
        : name(n), expirationDate(ed), weight(w) {}
    
    virtual ~FoodItem() = default;
    virtual void display() const {
        std::cout << name << " | " << expirationDate << " | " << weight << "kg | Поставщики: ";
        for(size_t i=0; i<suppliers.size(); ++i) std::cout << suppliers[i] << (i<suppliers.size()-1?", ":"\n");
    }
    virtual void saveToFile(std::ofstream& file) const = 0;
    virtual void loadFromFile(const std::string& data) = 0;
    
    void addSupplier(const std::string& s) { suppliers.push_back(s); }
    std::string getExpDate() const { return expirationDate; }
    double getWeight() const { return weight; }
    const std::vector<std::string>& getSuppliers() const { return suppliers; }
    void setExpDate(const std::string& ed) { expirationDate = ed; }
    void setWeight(double w) { weight = w; }
    
    bool isExpired() const {
        // Простая проверка: сравниваем строки дат
        // Формат YYYY-MM-DD позволяет лексикографическое сравнение
        time_t now = time(nullptr);
        tm* currentTm = localtime(&now);
        char currentDate[11];
        strftime(currentDate, 11, "%Y-%m-%d", currentTm);
        return expirationDate < std::string(currentDate);
    }
};

class Vegetable : public FoodItem {
    std::string type;
    int calories;
public:
    Vegetable(const std::string& n="", const std::string& ed="", double w=0.0, const std::string& t="", int c=0)
        : FoodItem(n,ed,w), type(t), calories(c) {}
    
    void display() const override {
        std::cout << "[Овощ] ";
        FoodItem::display();
        std::cout << "Тип: " << type << " | Калории: " << calories << "\n\n";
    }
    
    void saveToFile(std::ofstream& file) const override {
        file << "Vegetable;" << name << ";" << expirationDate << ";" << weight << ";" << type << "-" << calories << ";";
        for(size_t i=0; i<suppliers.size(); ++i) file << suppliers[i] << (i<suppliers.size()-1?"|":"");
    }
    
    void loadFromFile(const std::string& data) override {
        std::vector<std::string> parts;
        std::stringstream ss(data);
        std::string part;
        while(std::getline(ss, part, ';')) parts.push_back(part);
        if(parts.size()>=6) {
            name=parts[1]; expirationDate=parts[2]; weight=std::stod(parts[3]);
            size_t dash=parts[4].find('-');
            type=parts[4].substr(0,dash); calories=std::stoi(parts[4].substr(dash+1));
            suppliers.clear();
            std::stringstream supStream(parts[5]);
            std::string supplier;
            while(std::getline(supStream, supplier, '|')) {
                suppliers.push_back(supplier);
            }
        }
    }
    
    int getCalories() const { return calories; }
    std::string getName() const { return name; }
};

class DairyProduct : public FoodItem {
    double fat, protein;
public:
    DairyProduct(const std::string& n="", const std::string& ed="", double w=0.0, double f=0.0, double p=0.0)
        : FoodItem(n,ed,w), fat(f), protein(p) {}
    
    void display() const override {
        std::cout << "[Молочный] ";
        FoodItem::display();
        std::cout << "Жир: " << fat << "% | Белок: " << protein << "%\n\n";
    }
    
    void saveToFile(std::ofstream& file) const override {
        file << "Dairy;" << name << ";" << expirationDate << ";" << weight << ";" << fat << "-Protein" << protein << ";";
        for(size_t i=0; i<suppliers.size(); ++i) file << suppliers[i] << (i<suppliers.size()-1?"|":"");
    }
    
    void loadFromFile(const std::string& data) override {
        std::vector<std::string> parts;
        std::stringstream ss(data);
        std::string part;
        while(std::getline(ss, part, ';')) parts.push_back(part);
        if(parts.size()>=6) {
            name=parts[1]; expirationDate=parts[2]; weight=std::stod(parts[3]);
            size_t pos=parts[4].find("Protein");
            fat=std::stod(parts[4].substr(0,pos)); protein=std::stod(parts[4].substr(pos+7));
            suppliers.clear();
            std::stringstream supStream(parts[5]);
            std::string supplier;
            while(std::getline(supStream, supplier, '|')) {
                suppliers.push_back(supplier);
            }
        }
    }
    
    std::string getName() const { return name; }
};

class FoodManager {
    std::vector<std::unique_ptr<FoodItem>> items;
    
    void editItem(FoodItem* item) {
        std::string d; double w;
        std::cout << "Новая дата (ГГГГ-ММ-ДД): "; std::cin >> d; item->setExpDate(d);
        std::cout << "Новый вес: "; std::cin >> w; item->setWeight(w);
        std::cout << "Добавить поставщика? (y/n): ";
        char c; std::cin >> c;
        if(c=='y'||c=='Y') { std::string s; std::cout << "Поставщик: "; std::cin >> s; item->addSupplier(s); }
    }
    
public:
    void load(const std::string& fname) {
        std::ifstream f(fname);
        if(!f) { std::cerr << "Ошибка открытия файла\n"; return; }
        items.clear();
        std::string line;
        while(std::getline(f, line)) {
            if(line.empty()) continue;
            std::string type = line.substr(0, line.find(';'));
            if(type=="Vegetable") items.push_back(std::make_unique<Vegetable>());
            else if(type=="Dairy") items.push_back(std::make_unique<DairyProduct>());
            else continue;
            items.back()->loadFromFile(line);
        }
        std::cout << "Загружено: " << items.size() << "\n";
    }
    
    void save(const std::string& fname) const {
        std::ofstream f(fname);
        for(const auto& i: items) { i->saveToFile(f); f << "\n"; }
        std::cout << "Сохранено\n";
    }
    
    void show() const {
        if(items.empty()) { std::cout << "Пусто\n"; return; }
        for(const auto& i: items) i->display();
    }
    
    void add() {
        int t; std::string n,d; double w;
        std::cout << "Тип (1-овощ,2-молочный): "; std::cin >> t;
        std::cout << "Название: "; std::cin >> n;
        std::cout << "Дата (ГГГГ-ММ-ДД): "; std::cin >> d;
        std::cout << "Вес: "; std::cin >> w;
        
        if(t==1) {
            std::string ty; int c;
            std::cout << "Тип овоща: "; std::cin >> ty;
            std::cout << "Калории: "; std::cin >> c;
            items.push_back(std::make_unique<Vegetable>(n,d,w,ty,c));
        } else {
            double f,p;
            std::cout << "Жир: "; std::cin >> f;
            std::cout << "Белок: "; std::cin >> p;
            items.push_back(std::make_unique<DairyProduct>(n,d,w,f,p));
        }
        std::cout << "Добавлено\n";
    }
    
    void edit() {
        if(items.empty()) { std::cout << "Пусто\n"; return; }
        size_t idx; std::cout << "Номер (1-" << items.size() << "): "; std::cin >> idx;
        if(idx<1||idx>items.size()) { std::cout << "Неверно\n"; return; }
        editItem(items[idx-1].get());
        std::cout << "Отредактировано\n";
    }
    
    void del() {
        if(items.empty()) { std::cout << "Пусто\n"; return; }
        size_t idx; std::cout << "Номер (1-" << items.size() << "): "; std::cin >> idx;
        if(idx<1||idx>items.size()) { std::cout << "Неверно\n"; return; }
        items.erase(items.begin()+idx-1);
        std::cout << "Удалено\n";
    }
    
    void search() {
        int c; std::cout << "Поиск:1-имя,2-поставщик,3-калории: "; std::cin >> c;
        if(c==1) {
            std::string n; std::cout << "Имя: "; std::cin >> n;
            for(const auto& i: items) {
                if(auto v=dynamic_cast<Vegetable*>(i.get())) {
                    if(v->getName().find(n) != std::string::npos) i->display();
                } else if(auto d=dynamic_cast<DairyProduct*>(i.get())) {
                    if(d->getName().find(n) != std::string::npos) i->display();
                }
            }
        } else if(c==2) {
            std::string s; std::cout << "Поставщик: "; std::cin >> s;
            for(const auto& i: items) 
                if(std::find(i->getSuppliers().begin(), i->getSuppliers().end(), s) != i->getSuppliers().end()) 
                    i->display();
        } else if(c==3) {
            int m; std::cout << "Мин.калории: "; std::cin >> m;
            for(const auto& i: items) 
                if(auto v=dynamic_cast<Vegetable*>(i.get())) if(v->getCalories()>=m) i->display();
        }
    }
    
    void sortByWeight() {
        std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) { return a->getWeight() < b->getWeight(); });
        std::cout << "Отсортировано\n";
    }
    
    void removeExpired() {
        items.erase(std::remove_if(items.begin(), items.end(), [](const auto& i) { return i->isExpired(); }), items.end());
        std::cout << "Просроченные удалены\n";
    }
    
    void totalWeight() {
        double v=std::accumulate(items.begin(), items.end(), 0.0, [](double s, const auto& i) { 
            return dynamic_cast<Vegetable*>(i.get()) ? s + i->getWeight() : s; });
        double d=std::accumulate(items.begin(), items.end(), 0.0, [](double s, const auto& i) { 
            return dynamic_cast<DairyProduct*>(i.get()) ? s + i->getWeight() : s; });
        std::cout << "Овощи: " << v << "кг | Молочные: " << d << "кг\n";
    }
    
    void maxCalories() {
        auto it=std::max_element(items.begin(), items.end(), [](const auto& a, const auto& b) {
            auto va=dynamic_cast<Vegetable*>(a.get()), vb=dynamic_cast<Vegetable*>(b.get());
            if(!va) return true;
            if(!vb) return false;
            return va->getCalories() < vb->getCalories();
        });
        if(it!=items.end() && dynamic_cast<Vegetable*>((*it).get())) { 
            std::cout << "Самый калорийный овощ:\n"; 
            (*it)->display(); 
        }
        else std::cout << "Овощи не найдены\n";
    }
};

int main() {
    FoodManager m;
    int choice;
    do {
        std::cout << "\n1.Загрузить 2.Показать 3.Поиск 4.Сортировка 5.Добавить 6.Редактировать 7.Удалить 8.Сохранить 9.Удалить просроченные 10.Суммарный вес 11.Макс.калории 0.Выход\nВыбор: ";
        std::cin >> choice;
        if(choice==1) m.load("warehouse.txt");
        else if(choice==2) m.show();
        else if(choice==3) m.search();
        else if(choice==4) m.sortByWeight();
        else if(choice==5) m.add();
        else if(choice==6) m.edit();
        else if(choice==7) m.del();
        else if(choice==8) m.save("warehouse.txt");
        else if(choice==9) m.removeExpired();
        else if(choice==10) m.totalWeight();
        else if(choice==11) m.maxCalories();
    } while(choice != 0);
    
    return 0;
}