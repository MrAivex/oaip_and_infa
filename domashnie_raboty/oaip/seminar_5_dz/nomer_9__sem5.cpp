#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

void analyzeMotorPower() {
    std::cout << "=== Статистика по мощности электродвигателя ===" << std::endl;
    
    // 1. Создайте вектор мощности двигателя (20 измерений в кВт)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-5, 100); // включаем отрицательные для ошибок датчика
    std::vector<int> powers(20);
    std::generate(powers.begin(), powers.end(), [&](){ return dis(gen); });
    
    std::cout << "Исходные измерения: ";
    for(int p : powers) std::cout << p << " ";
    std::cout << std::endl;

    // 2. Удалите все измерения < 0 (ошибки датчика)
    powers.erase(std::remove_if(powers.begin(), powers.end(),
                               [](int p){ return p < 0; }),
                powers.end());
    
    std::cout << "После удаления ошибок: ";
    for(int p : powers) std::cout << p << " ";
    std::cout << std::endl;

    // 3. Найдите минимальную, максимальную и среднюю мощность
    auto [min_it, max_it] = std::minmax_element(powers.begin(), powers.end());
    double average = std::accumulate(powers.begin(), powers.end(), 0.0) / powers.size();
    
    std::cout << "Минимальная мощность: " << *min_it << std::endl;
    std::cout << "Максимальная мощность: " << *max_it << std::endl;
    std::cout << "Средняя мощность: " << average << std::endl;

    // 4. Проверьте, работал ли двигатель всё время в пределах от 10 до 90 кВт
    bool in_range = std::all_of(powers.begin(), powers.end(),
                               [](int p){ return p >= 10 && p <= 90; });
    std::cout << "Работа в диапазоне 10-90 кВт: " << (in_range ? "Да" : "Нет") << std::endl;

    // 5. Отсортируйте значения по возрастанию и вывести медиану
    std::sort(powers.begin(), powers.end());
    std::cout << "Отсортированные значения: ";
    for(int p : powers) std::cout << p << " ";
    std::cout << std::endl;
    
    double median;
    if (powers.size() % 2 == 0) {
        median = (powers[powers.size()/2 - 1] + powers[powers.size()/2]) / 2.0;
    } else {
        median = powers[powers.size()/2];
    }
    std::cout << "Медиана: " << median << std::endl;
}

int main() {
    analyzeMotorPower();
    return 0;
}