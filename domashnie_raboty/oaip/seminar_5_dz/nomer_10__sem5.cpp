#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

int main() {
    // 1. Создание вектора потребления энергии за 30 дней
    std::vector<double> energy_consumption = {
        120.5, 135.0, 110.2, 145.8, 160.3, 
        155.5, 168.4, 175.2, 130.1, 142.7,
        148.9, 165.3, 170.1, 125.6, 138.4,
        152.0, 158.7, 162.3, 140.8, 148.2,
        155.1, 167.9, 172.5, 132.4, 144.6,
        150.9, 163.4, 168.8, 128.3, 141.5
    };

    // 2. Расчёт общего потребления за месяц
    double total_energy = std::accumulate(
        energy_consumption.begin(), 
        energy_consumption.end(), 
        0.0
    );

    // 3. Определение среднесуточного значения
    double average_consumption = total_energy / energy_consumption.size();

    // 4. Поиск дней с максимальным и минимальным потреблением
    auto [min_it, max_it] = std::minmax_element(
        energy_consumption.begin(), 
        energy_consumption.end()
    );
    int min_day = std::distance(energy_consumption.begin(), min_it) + 1;
    int max_day = std::distance(energy_consumption.begin(), max_it) + 1;

    // 5. Фильтрация пиковых дней (потребление > среднего на 20%)
    double threshold = average_consumption * 1.2;
    std::vector<int> peak_days;
    for (size_t i = 0; i < energy_consumption.size(); ++i) {
        if (energy_consumption[i] > threshold) {
            peak_days.push_back(i + 1); // Сохраняем номера дней (начиная с 1)
        }
    }

    // Вывод результатов
    std::cout << "Общее потребление за месяц: " << total_energy << " кВт·ч\n";
    std::cout << "Среднесуточное потребление: " << average_consumption << " кВт·ч\n";
    std::cout << "День с минимальным потреблением: " << min_day << " (" << *min_it << " кВт·ч)\n";
    std::cout << "День с максимальным потреблением: " << max_day << " (" << *max_it << " кВт·ч)\n";
    std::cout << "Порог для пиковых дней: " << threshold << " кВт·ч\n";
    std::cout << "Пиковые дни: ";
    for (int day : peak_days) {
        std::cout << day << " ";
    }
    std::cout << std::endl;

    return 0;
}