#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

int main() {
    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(50.0, 1000.0); // Диапазон уровней топлива

    // 1. Создание вектора уровня топлива (50 замеров)
    vector<double> fuel_levels;
    for (int i = 0; i < 50; ++i) {
        fuel_levels.push_back(dis(gen));
    }

    // 2. Поиск минимального уровня топлива
    double min_fuel = *min_element(fuel_levels.begin(), fuel_levels.end());
    cout << "Минимальный уровень топлива: " << min_fuel << endl;

    // 3. Проверка падения уровня ниже 5% от максимального
    double max_fuel = *max_element(fuel_levels.begin(), fuel_levels.end());
    double critical_level = 0.05 * max_fuel;
    bool is_below_critical = any_of(fuel_levels.begin(), fuel_levels.end(),
        [critical_level](double level) { return level < critical_level; });
    
    cout << "Максимальный уровень топлива: " << max_fuel << endl;
    cout << "Критический уровень (5% от макс.): " << critical_level << endl;
    cout << "Падение ниже критического уровня: " 
         << (is_below_critical ? "Да" : "Нет") << endl;

    // 4. Расчет среднего потребления
    double consumption = fuel_levels.front() - fuel_levels.back();
    cout << "Среднее потребление: " << consumption << endl;

    // 5. Поиск медианы
    vector<double> sorted_fuel = fuel_levels;
    sort(sorted_fuel.begin(), sorted_fuel.end());
    
    double median;
    if (sorted_fuel.size() % 2 == 0) {
        median = (sorted_fuel[sorted_fuel.size()/2 - 1] + sorted_fuel[sorted_fuel.size()/2]) / 2;
    } else {
        median = sorted_fuel[sorted_fuel.size()/2];
    }
    
    cout << "Медианный уровень топлива: " << median << endl;

    return 0;
}
