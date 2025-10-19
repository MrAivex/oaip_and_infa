#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для решения системы линейных уравнений методом Гаусса
vector<double> gauss(vector<vector<double>> A, vector<double> b) {
    int n = A.size();
    
    // Прямой ход метода Гаусса
    for (int i = 0; i < n; i++) {
        // Поиск главного элемента
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        
        // Перестановка строк
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);
        
        // Проверка на вырожденность
        if (abs(A[i][i]) < 1e-10) {
            throw runtime_error("Матрица вырождена");
        }
        
        // Обнуление элементов под главной диагональю
        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }
    
    // Обратный ход метода Гаусса
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    
    return x;
}

int main() {
    // Координаты четырех точек
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
    
    cout << "Введите координаты четырех точек:" << endl;
    cout << "Точка 1 (x1 y1 z1): ";
    cin >> x1 >> y1 >> z1;
    cout << "Точка 2 (x2 y2 z2): ";
    cin >> x2 >> y2 >> z2;
    cout << "Точка 3 (x3 y3 z3): ";
    cin >> x3 >> y3 >> z3;
    cout << "Точка 4 (x4 y4 z4): ";
    cin >> x4 >> y4 >> z4;
    
    try {
        // Формируем систему уравнений для коэффициентов A, B, C, D
        // Уравнение сферы: x² + y² + z² + Ax + By + Cz + D = 0
        
        vector<vector<double>> A = {
            {x1, y1, z1, 1},
            {x2, y2, z2, 1},
            {x3, y3, z3, 1},
            {x4, y4, z4, 1}
        };
        
        vector<double> b = {
            -(x1*x1 + y1*y1 + z1*z1),
            -(x2*x2 + y2*y2 + z2*z2),
            -(x3*x3 + y3*y3 + z3*z3),
            -(x4*x4 + y4*y4 + z4*z4)
        };
        
        // Решаем систему методом Гаусса
        vector<double> coefficients = gauss(A, b);
        double A_coef = coefficients[0];
        double B_coef = coefficients[1];
        double C_coef = coefficients[2];
        double D_coef = coefficients[3];
        
        // Находим центр и радиус сферы
        double x0 = -A_coef / 2;
        double y0 = -B_coef / 2;
        double z0 = -C_coef / 2;
        double r = sqrt(x0*x0 + y0*y0 + z0*z0 - D_coef);
        
        // Вывод результатов
        cout << "\nУравнение сферы:" << endl;
        cout << "x² + y² + z² ";
        if (A_coef >= 0) cout << "+ " << A_coef << "x ";
        else cout << "- " << -A_coef << "x ";
        
        if (B_coef >= 0) cout << "+ " << B_coef << "y ";
        else cout << "- " << -B_coef << "y ";
        
        if (C_coef >= 0) cout << "+ " << C_coef << "z ";
        else cout << "- " << -C_coef << "z ";
        
        if (D_coef >= 0) cout << "+ " << D_coef;
        else cout << "- " << -D_coef;
        
        cout << " = 0" << endl;
        
        cout << "\nЦентр сферы: (" << x0 << ", " << y0 << ", " << z0 << ")" << endl;
        cout << "Радиус сферы: " << r << endl;
        
        // Каноническое уравнение
        cout << "\nКаноническое уравнение сферы:" << endl;
        cout << "(x " << (x0 >= 0 ? "- " : "+ ") << abs(x0) << ")² + ";
        cout << "(y " << (y0 >= 0 ? "- " : "+ ") << abs(y0) << ")² + ";
        cout << "(z " << (z0 >= 0 ? "- " : "+ ") << abs(z0) << ")² = ";
        cout << r*r << endl;
        
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
        cout << "Точки лежат в одной плоскости или образуют вырожденную сферу" << endl;
    }
    
    return 0;
}