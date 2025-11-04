#include <iostream>
#include <vector>

using namespace std;

void analyzePressure(const vector<double>& data, double& minVal, double& maxVal, double& avgVal) {
    const double* p = data.data();
    size_t size = data.size();
    
    if (size == 0) {
        minVal = maxVal = avgVal = 0;
        return;
    }
    
    minVal = *p;
    maxVal = *p;
    double sum = 0;
    
    for (size_t i = 0; i < size; i++) {
        double current = *(p + i);
        
        if (current < minVal) minVal = current;
        if (current > maxVal) maxVal = current;
        sum += current;
    }
    
    avgVal = sum / size;
}

int main() {
    vector<double> pressure = {101.3, 100.8, 101.9, 100.5, 102.0};
    
    double minVal, maxVal, avgVal;
    analyzePressure(pressure, minVal, maxVal, avgVal);
    
    cout << "Давление: ";
    for (double val : pressure) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "Минимальное давление: " << minVal << endl;
    cout << "Максимальное давление: " << maxVal << endl;
    cout << "Среднее давление: " << avgVal << endl;
    
    return 0;
}