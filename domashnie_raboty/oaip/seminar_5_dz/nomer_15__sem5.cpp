#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <iomanip>
#include <limits>

int main() {
    // Инициализация генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> temp_dist(20.0, 100.0);  // температура 20-100°C
    std::uniform_real_distribution<double> pressure_dist(1.0, 10.0); // давление 1-10 бар
    
    // 1. Инициализация данных
    std::vector<std::vector<double>> temp(5, std::vector<double>(30));
    std::vector<std::vector<double>> pressure(5, std::vector<double>(100));
    
    // Заполнение случайными данными
    for (auto& channel : temp) {
        std::generate(channel.begin(), channel.end(), [&]() { return temp_dist(gen); });
    }
    
    for (auto& channel : pressure) {
        std::generate(channel.begin(), channel.end(), [&]() { return pressure_dist(gen); });
    }
    
    std::cout << "=== МНОГОКАНАЛЬНЫЙ МОНИТОРИНГ ТЕМПЕРАТУРЫ И ДАВЛЕНИЯ ===\n\n";
    
    // 2. Для каждого канала температуры рассчитать среднюю температуру
    std::vector<double> avg_temperatures(5);
    std::transform(temp.begin(), temp.end(), avg_temperatures.begin(),
                  [](const std::vector<double>& channel) {
                      double sum = std::accumulate(channel.begin(), channel.end(), 0.0);
                      return sum / channel.size();
                  });
    
    std::cout << "1. Средние температуры по каналам:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Канал " << i + 1 << ": " << std::fixed << std::setprecision(2) 
                  << avg_temperatures[i] << "°C\n";
    }
    std::cout << std::endl;
    
    // 3. Для каждого канала давления найти минимальное и максимальное давление
    std::vector<std::pair<double, double>> minmax_pressures(5);
    std::transform(pressure.begin(), pressure.end(), minmax_pressures.begin(),
                  [](const std::vector<double>& channel) {
                      auto [min_it, max_it] = std::minmax_element(channel.begin(), channel.end());
                      return std::make_pair(*min_it, *max_it);
                  });
    
    std::cout << "2. Минимальное и максимальное давление по каналам:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Канал " << i + 1 << ": min=" << std::fixed << std::setprecision(2) 
                  << minmax_pressures[i].first << " бар, max=" << minmax_pressures[i].second 
                  << " бар\n";
    }
    std::cout << std::endl;
    
    // 4. Рассчитать разности между соседними измерениями для температуры и давления
    std::vector<std::vector<double>> temp_differences(5);
    std::vector<std::vector<double>> pressure_differences(5);
    
    for (int i = 0; i < 5; ++i) {
        // Разности для температуры
        temp_differences[i].resize(temp[i].size() - 1);
        std::transform(temp[i].begin(), temp[i].end() - 1, temp[i].begin() + 1,
                      temp_differences[i].begin(),
                      [](double a, double b) { return b - a; });
        
        // Разности для давления
        pressure_differences[i].resize(pressure[i].size() - 1);
        std::transform(pressure[i].begin(), pressure[i].end() - 1, pressure[i].begin() + 1,
                      pressure_differences[i].begin(),
                      [](double a, double b) { return b - a; });
    }
    
    std::cout << "3. Пример разностей для канала 1 (первые 5 значений):\n";
    std::cout << "Температура: ";
    for (int i = 0; i < 5 && i < temp_differences[0].size(); ++i) {
        std::cout << std::setw(7) << std::fixed << std::setprecision(2) 
                  << temp_differences[0][i] << " ";
    }
    std::cout << "\nДавление:    ";
    for (int i = 0; i < 5 && i < pressure_differences[0].size(); ++i) {
        std::cout << std::setw(7) << std::fixed << std::setprecision(2) 
                  << pressure_differences[0][i] << " ";
    }
    std::cout << "\n\n";
    
    // 5. Определить канал с наибольшей вариацией температуры (разность max-min)
    std::vector<double> temp_variations(5);
    std::transform(temp.begin(), temp.end(), temp_variations.begin(),
                  [](const std::vector<double>& channel) {
                      auto [min_it, max_it] = std::minmax_element(channel.begin(), channel.end());
                      return *max_it - *min_it;
                  });
    
    auto max_var_it = std::max_element(temp_variations.begin(), temp_variations.end());
    int max_var_channel = std::distance(temp_variations.begin(), max_var_it);
    
    std::cout << "4. Канал с наибольшей вариацией температуры:\n";
    std::cout << "Канал " << max_var_channel + 1 << " с вариацией " 
              << std::fixed << std::setprecision(2) << *max_var_it << "°C\n\n";
    
    // 6. Для каждого канала давления нормализовать значения: (value - min)/(max - min)
    std::vector<std::vector<double>> normalized_pressure(5);
    for (int i = 0; i < 5; ++i) {
        double min_val = minmax_pressures[i].first;
        double max_val = minmax_pressures[i].second;
        double range = max_val - min_val;
        
        normalized_pressure[i].resize(pressure[i].size());
        std::transform(pressure[i].begin(), pressure[i].end(), normalized_pressure[i].begin(),
                      [min_val, range](double value) {
                          return (value - min_val) / range;
                      });
    }
    
    std::cout << "5. Пример нормализованных значений давления для канала 1 (первые 10):\n";
    for (int i = 0; i < 10 && i < normalized_pressure[0].size(); ++i) {
        std::cout << std::fixed << std::setprecision(3) << normalized_pressure[0][i] << " ";
    }
    std::cout << "\n\n";
    
    // 7. Вывести все значения давления после нормализации, которые превышают 0.9 (пики)
    std::cout << "6. Пики давления (нормализованные значения > 0.9):\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Канал " << i + 1 << ": ";
        std::for_each(normalized_pressure[i].begin(), normalized_pressure[i].end(),
                     [i](double value) {
                         if (value > 0.9) {
                             std::cout << std::fixed << std::setprecision(3) << value << " ";
                         }
                     });
        std::cout << "\n";
    }
    std::cout << std::endl;
    
    // 8. Отсортировать средние температуры каналов и вывести канал с максимальной средней температурой
    std::vector<std::pair<double, int>> temp_with_index(5);
    for (int i = 0; i < 5; ++i) {
        temp_with_index[i] = {avg_temperatures[i], i};
    }
    
    // Сортировка по убыванию температуры
    std::sort(temp_with_index.begin(), temp_with_index.end(),
             [](const auto& a, const auto& b) { return a.first > b.first; });
    
    std::cout << "7. Каналы, отсортированные по средней температуре:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 << ". Канал " << temp_with_index[i].second + 1 
                  << ": " << std::fixed << std::setprecision(2) << temp_with_index[i].first 
                  << "°C\n";
    }
    
    std::cout << "\nКанал с максимальной средней температурой: Канал " 
              << temp_with_index[0].second + 1 << " (" 
              << std::fixed << std::setprecision(2) << temp_with_index[0].first << "°C)\n";
    
    return 0;
}