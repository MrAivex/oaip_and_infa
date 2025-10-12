#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

void analyzeCarSpeed() {
    std::cout << "=== Анализ скорости автомобиля ===" << std::endl;
    
    // 1. Создайте вектор значений скорости автомобиля (50 значений, от 0 до 180)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 180);
    std::vector<int> speeds(50);
    std::generate(speeds.begin(), speeds.end(), [&](){ return dis(gen); });
    
    std::cout << "Все скорости: ";
    for(int s : speeds) std::cout << s << " ";
    std::cout << std::endl;

    // 2. Отфильтруйте все превышения скорости > 120
    std::vector<int> overspeeds;
    std::copy_if(speeds.begin(), speeds.end(),
                 std::back_inserter(overspeeds),
                 [](int s){ return s > 120; });
    
    std::cout << "Превышения скорости (>120): ";
    for(int s : overspeeds) std::cout << s << " ";
    std::cout << std::endl;

    // 3. Найдите среднюю скорость
    double average = std::accumulate(speeds.begin(), speeds.end(), 0.0) / speeds.size();
    std::cout << "Средняя скорость: " << average << std::endl;

    // 4. Определите, были ли все значения больше 0 (двигался ли всегда)
    bool always_moving = std::all_of(speeds.begin(), speeds.end(), [](int s){ return s > 0; });
    std::cout << "Всегда в движении: " << (always_moving ? "Да" : "Нет") << std::endl;

    // 5. Выведите 10 максимальных значений скорости
    std::vector<int> top10(10);
    std::partial_sort_copy(speeds.begin(), speeds.end(),
                          top10.begin(), top10.end(),
                          std::greater<int>());
    
    std::cout << "Топ-10 скоростей: ";
    for(int s : top10) std::cout << s << " ";
    std::cout << std::endl;
}

int main() {
    analyzeCarSpeed();
    return 0;
}