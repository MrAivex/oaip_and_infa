#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>

class VibrationAnalyzer {
private:
    std::vector<double> amplitudes;
    
public:
    VibrationAnalyzer(const std::vector<double>& data) : amplitudes(data) {}
    
    void removeNoise(double threshold = 0.1) {
        amplitudes.erase(
            std::remove_if(amplitudes.begin(), amplitudes.end(),
                          [threshold](double amp) { return amp < threshold; }),
            amplitudes.end()
        );
    }
    
    double getAverage() const {
        if (amplitudes.empty()) return 0.0;
        return std::accumulate(amplitudes.begin(), amplitudes.end(), 0.0) / amplitudes.size();
    }
    
    double getMax() const {
        if (amplitudes.empty()) return 0.0;
        return *std::max_element(amplitudes.begin(), amplitudes.end());
    }
    
    double getMin() const {
        if (amplitudes.empty()) return 0.0;
        return *std::min_element(amplitudes.begin(), amplitudes.end());
    }
    
    bool checkThreshold(double threshold) const {
        return std::all_of(amplitudes.begin(), amplitudes.end(),
                          [threshold](double amp) { return amp > threshold; });
    }
    
    std::vector<double> getTopAmplitudes(int count) const {
        std::vector<double> sorted = amplitudes;
        std::sort(sorted.begin(), sorted.end(), std::greater<double>());
        
        if (sorted.size() > count) {
            return std::vector<double>(sorted.begin(), sorted.begin() + count);
        }
        return sorted;
    }
    
    double getStandardDeviation() const {
        if (amplitudes.empty()) return 0.0;
        double mean = getAverage();
        double sum_sq = 0.0;
        for (double amp : amplitudes) {
            sum_sq += (amp - mean) * (amp - mean);
        }
        return std::sqrt(sum_sq / amplitudes.size());
    }
    
    void printAnalysis() const {
        std::cout << "=== РЕЗУЛЬТАТЫ ВИБРОАНАЛИЗА ===\n";
        std::cout << "Образцов: " << amplitudes.size() << "\n";
        std::cout << "Средняя амплитуда: " << getAverage() << "\n";
        std::cout << "Максимальная амплитуда: " << getMax() << "\n";
        std::cout << "Минимальная амплитуда: " << getMin() << "\n";
        std::cout << "Стандартное отклонение: " << getStandardDeviation() << "\n";
        std::cout << "Все значения > 0.5: " << (checkThreshold(0.5) ? "Да" : "Нет") << "\n";
        
        auto top_10 = getTopAmplitudes(10);
        std::cout << "10 наибольших амплитуд: ";
        for (double amp : top_10) {
            std::cout << amp << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    // Создание тестовых данных
    std::vector<double> test_data = {
        0.08, 0.15, 0.32, 0.45, 0.67, 0.89, 1.12, 1.45, 1.78, 2.01,
        0.12, 0.28, 0.51, 0.73, 0.94, 1.16, 1.39, 1.62, 1.85, 2.08,
        0.09, 0.21, 0.43, 0.65, 0.87, 1.09, 1.31, 1.53, 1.75, 1.97,
        0.11, 0.25, 0.48, 0.71, 0.93, 1.15, 1.37, 1.59, 1.81, 2.03,
        0.07, 0.19, 0.41, 0.63, 0.85, 1.07, 1.29, 1.51, 1.73, 1.95
    };
    
    VibrationAnalyzer analyzer(test_data);
    analyzer.removeNoise(0.1);
    analyzer.printAnalysis();
    
    return 0;
}