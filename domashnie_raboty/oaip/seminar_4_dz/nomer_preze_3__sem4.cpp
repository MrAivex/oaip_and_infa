#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    
    // Ввод координат трех точек
    cout << "Введите координаты точки A (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Введите координаты точки B (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Введите координаты точки C (x3 y3): ";
    cin >> x3 >> y3;
    
    // Вычисление определителя матрицы 3x3
    double det = x1 * (y2 - y3) 
               - x2 * (y1 - y3) 
               + x3 * (y1 - y2);
    
    // Проверка коллинеарности с учетом погрешности вычислений
    double epsilon = 1e-9; // Малая величина для учета погрешности
    
    if (fabs(det) < epsilon) {
        cout << "Точки коллинеарны (лежат на одной прямой)" << endl;
    } else {
        cout << "Точки не коллинеарны" << endl;
    }
    
    return 0;
}