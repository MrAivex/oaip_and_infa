#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double computeRMS(const vector<double>& signal) {
    const double* p = signal.data();
    size_t N = signal.size();
    double sum_squares = 0.0;
    
    for (size_t i = 0; i < N; i++) {
        double value = *(p + i);
        sum_squares += value * value;
    }
    
    return sqrt(sum_squares / N);
}

int main() {
    vector<double> signal = {2.0, 3.0, 1.0, 4.0, 3.0};
    
    cout << "Сигнал: ";
    for (double val : signal) {
        cout << val << " ";
    }
    cout << endl;
    
    double rms = computeRMS(signal);
    cout << "RMS значение: " << rms << endl;
    
    return 0;
}