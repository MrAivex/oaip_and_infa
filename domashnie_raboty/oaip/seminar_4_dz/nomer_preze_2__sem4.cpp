#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, theta;
    
    // Ввод координат точки и угла поворота
    cout << "Введите координаты точки (x y): ";
    cin >> x >> y;
    cout << "Введите угол поворота в градусах: ";
    cin >> theta;
    
    // Преобразование градусов в радианы
    double theta_rad = theta * M_PI / 180.0;
    
    // Вычисление новых координат после поворота
    double x_new = x * cos(theta_rad) + y * sin(theta_rad);
    double y_new = -x * sin(theta_rad) + y * cos(theta_rad);
    
    // Вывод результата
    cout << "Новые координаты точки после поворота на " << theta << " градусов:" << endl;
    cout << "x' = " << x_new << endl;
    cout << "y' = " << y_new << endl;
    
    return 0;
}