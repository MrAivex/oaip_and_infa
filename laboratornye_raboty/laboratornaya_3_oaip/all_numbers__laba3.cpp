#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

struct Dish {
    string name;
    string type;
    double price;
};

const vector<string> TYPES = {"Закуски", "Основные блюда", "Десерты", "Напитки", "Для детей"};

void logMessage(ofstream& outputFile, const string& message) {
    cout << message;
    outputFile << message;
}

Dish inputDish() {
    Dish dish;
    cout << "Введите название блюда: ";
    getline(cin, dish.name);
    
    if (dish.name.empty()) return dish;
    
    cout << "Выберите тип блюда:\n";
    for (size_t i = 0; i < TYPES.size(); i++) {
        cout << i + 1 << ". " << TYPES[i] << endl;
    }
    
    int typeChoice;
    while (true) {
        cout << "Введите номер типа: ";
        cin >> typeChoice;
        if (typeChoice >= 1 && typeChoice <= static_cast<int>(TYPES.size())) {
            break;
        }
        cout << "Неверный выбор! Попробуйте снова.\n";
    }
    dish.type = TYPES[typeChoice - 1];
    
    cout << "Введите цену блюда: ";
    cin >> dish.price;
    cin.ignore(); // Очистка буфера
    
    return dish;
}

void saveDishToFile(ofstream& file, const Dish& dish) {
    file << dish.name << ";" << dish.type << ";" << dish.price << endl;
}

void createAndFillFile() {
    ofstream file("menu.txt");
    ofstream output("output.txt", ios::app);
    
    if (!file.is_open() || !output.is_open()) {
        cout << "Ошибка открытия файлов!" << endl;
        return;
    }
    
    logMessage(output, "=== ЗАПОЛНЕНИЕ ФАЙЛА МЕНЮ ===\n");
    
    while (true) {
        Dish dish = inputDish();
        
        if (dish.name.empty()) {
            break;
        }
        
        saveDishToFile(file, dish);
        logMessage(output, "Добавлено блюдо: " + dish.name + " (" + dish.type + ") - " + 
                   to_string(dish.price) + " руб.\n");
    }
    
    file.close();
    output.close();
}

vector<Dish> readAllDishes() {
    vector<Dish> dishes;
    ifstream file("menu.txt");
    
    if (!file.is_open()) {
        return dishes;
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, type, priceStr;
        
        getline(ss, name, ';');
        getline(ss, type, ';');
        getline(ss, priceStr, ';');
        
        Dish dish;
        dish.name = name;
        dish.type = type;
        dish.price = stod(priceStr);
        
        dishes.push_back(dish);
    }
    
    file.close();
    return dishes;
}

void searchDish() {
    ofstream output("output.txt", ios::app);
    logMessage(output, "\n=== ПОИСК БЛЮДА ===\n");
    
    string searchName;
    cout << "Введите название блюда для поиска: ";
    getline(cin, searchName);
    
    vector<Dish> dishes = readAllDishes();
    bool found = false;
    
    for (const auto& dish : dishes) {
        if (dish.name == searchName) {
            logMessage(output, "Найдено блюдо: " + dish.name + " (" + dish.type + 
                       ") - " + to_string(dish.price) + " руб.\n");
            found = true;
            break;
        }
    }
    
    if (!found) {
        logMessage(output, "Блюдо с названием '" + searchName + "' не найдено.\n");
    }
    
    output.close();
}

bool compareByType(const Dish& a, const Dish& b) {
    return a.type < b.type;
}

bool compareByPrice(const Dish& a, const Dish& b) {
    return a.price < b.price;
}

void sortDishes() {
    ofstream output("output.txt", ios::app);
    logMessage(output, "\n=== СОРТИРОВКА БЛЮД ===\n");
    
    int choice;
    cout << "Выберите тип сортировки: " << endl;
    cout << "1. По типу блюда" << endl;
    cout << "2. По цене" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    cin.ignore();
    
    vector<Dish> dishes = readAllDishes();
    
    if (choice == 1) {
        sort(dishes.begin(), dishes.end(), compareByType);
        logMessage(output, "Сортировка по типу блюда:\n");
    } else if (choice == 2) {
        sort(dishes.begin(), dishes.end(), compareByPrice);
        logMessage(output, "Сортировка по цене:\n");
    } else {
        logMessage(output, "Неверный выбор сортировки!\n");
        output.close();
        return;
    }

    ofstream file("menu.txt");
    for (const auto& dish : dishes) {
        saveDishToFile(file, dish);
        logMessage(output, dish.name + " (" + dish.type + ") - " + 
                   to_string(dish.price) + " руб.\n");
    }
    
    file.close();
    output.close();
}

void addNewDish() {
    ofstream file("menu.txt", ios::app);
    ofstream output("output.txt", ios::app);
    
    logMessage(output, "\n=== ДОБАВЛЕНИЕ НОВОГО БЛЮДА ===\n");
    
    Dish dish = inputDish();
    if (!dish.name.empty()) {
        saveDishToFile(file, dish);
        logMessage(output, "Добавлено новое блюдо: " + dish.name + " (" + dish.type + 
                   ") - " + to_string(dish.price) + " руб.\n");
    }
    
    file.close();
    output.close();
}

void showDishesByPrice() {
    ofstream output("output.txt", ios::app);
    logMessage(output, "\n=== ПОИСК БЛЮД ПО ЦЕНЕ ===\n");
    
    double maxPrice;
    cout << "Введите максимальную цену: ";
    cin >> maxPrice;
    cin.ignore();
    
    vector<Dish> dishes = readAllDishes();
    bool found = false;
    
    logMessage(output, "Блюда с ценой до " + to_string(maxPrice) + " руб.:\n");
    
    for (const auto& dish : dishes) {
        if (dish.price <= maxPrice) {
            logMessage(output, dish.name + " (" + dish.type + ") - " + 
                       to_string(dish.price) + " руб.\n");
            found = true;
        }
    }
    
    if (!found) {
        logMessage(output, "Блюда с ценой до " + to_string(maxPrice) + " руб. не найдены.\n");
    }
    
    output.close();
}

void showMenu() {
    ofstream output("output.txt", ios::app);
    
    while (true) {
        cout << "\n=== МЕНЮ РЕСТОРАНА ===\n";
        cout << "1. Создать и заполнить меню\n";
        cout << "2. Найти блюдо по названию\n";
        cout << "3. Сортировать блюда\n";
        cout << "4. Добавить новое блюдо\n";
        cout << "5. Найти блюда по цене\n";
        cout << "6. Выход\n";
        cout << "Выберите действие: ";
        
        int choice;
        cin >> choice;
        cin.ignore();
        
        logMessage(output, "\nПользователь выбрал: " + to_string(choice) + "\n");
        
        switch (choice) {
            case 1:
                createAndFillFile();
                break;
            case 2:
                searchDish();
                break;
            case 3:
                sortDishes();
                break;
            case 4:
                addNewDish();
                break;
            case 5:
                showDishesByPrice();
                break;
            case 6:
                logMessage(output, "=== ВЫХОД ИЗ ПРОГРАММЫ ===\n");
                output.close();
                cout << "До свидания!" << endl;
                return;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                logMessage(output, "Неверный выбор меню\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "Программа для управления меню ресторана" << endl;
    showMenu();
    
    return 0;
}