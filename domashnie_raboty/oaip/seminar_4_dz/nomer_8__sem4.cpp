#include <iostream>
#include <vector>

using namespace std;

int main() {
    float matrix[3][3];

    cout << "Введите матрицу" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Введите введите элемент строки " << i + 1 << " столбца " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << "Введите значения выражений по порядку " << endl;

    float corni[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Введите решение " << i + 1 << ": ";
        cin >> corni[i];
    }

    float x1 = matrix[0][0], x2 = matrix[1][0], x3 = matrix[2][0];
    float y1 = matrix[0][1], y2 = matrix[1][1], y3 = matrix[2][1];
    float z1 = matrix[0][2], z2 = matrix[1][2], z3 = matrix[2][2];
    float c1 = corni[0], c2 = corni[1], c3 = corni[2];

    float det = x1 * (y2 * z3 - z2 * y3) - y1 * (x2 * z3 - z2 * x3) + z1 * (x2 * y3 - y2 * x3);
    float det1 = c1 * (y2 * z3 - z2 * y3) - y1 * (c2 * z3 - z2 * c3) + z1 * (c2 * y3 - y2 * c3);
    float det2 = x1 * (c2 * z3 - z2 * c3) - c1 * (x2 * z3 - z2 * x3) + z1 * (x2 * c3 - c2 * x3);
    float det3 = x1 * (y2 * c3 - c2 * y3) - y1 * (x2 * c3 - c2 * x3) + c1 * (x2 * y3 - y2 * x3);

    float x = det1 / det;
    float y = det2 / det;
    float z = det3 / det;

    cout << "x = " << x << endl << "y = " << y << "z = " << z << endl;
    
    return 0;
}