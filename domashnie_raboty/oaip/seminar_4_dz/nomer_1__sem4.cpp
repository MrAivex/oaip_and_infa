#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cout << "Введите N: ";
    cin >> n;

    int matrix[n][n];
    int transposed1[n][n];
    int transposed2[n][n];
    int transposed3[n][n];
    int transposed4[n][n];

    int k12 = 0;
    int k13 = 0;
    int k14 = 0;
    int k23 = 0;
    int k24 = 0;
    int k34 = 0;

    // Ввод чисел в матрицу

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Введите число: ";
            cin >> matrix[i][j];
        }
    }

    // Транспонирование матрицы относительно главной диагонали

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposed1[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << transposed1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Транспонирование относительно побочной диагонали

    int t2 = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposed2[t2 - j][t2 - i] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << transposed2[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Транспонирование относительно вертикальной оси

    int t3 = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposed3[i][t3 - j] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << transposed3[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Транспонирование относительно вертикальной оси

    int t4 = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposed4[t4 - i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << transposed4[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Сравнение матриц 1 и 2

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (transposed1[i][j] == transposed2[i][j])
            {
                k12++;
            }
        }
    }

    if (k12 == n * n)
    {
        cout << "(1, 2)" << endl;
    }

    // Сравнение матриц 1 и 3

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (transposed1[i][j] == transposed3[i][j])
            {
                k13++;
            }
        }
    }

    if (k13 == n * n)
    {
        cout << "(1, 3)" << endl;
    }

    // Сравнение матриц 1 и 4

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (transposed1[i][j] == transposed4[i][j])
            {
                k14++;
            }
        }
    }

    if (k14 == n * n)
    {
        cout << "(1, 4)" << endl;
    }

    // Сравнение матриц 2 и 3

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (transposed2[i][j] == transposed3[i][j])
            {
                k23++;
            }
        }
    }

    if (k23 == n * n)
    {
        cout << "(2, 3)" << endl;
    }

    // Сравнение матриц 2 и 4

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (transposed2[i][j] == transposed4[i][j])
            {
                k24++;
            }
        }
    }

    if (k24 == n * n)
    {
        cout << "(2, 4)" << endl;
    }

    // Сравнение матриц 3 и 4

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (transposed3[i][j] == transposed4[i][j])
            {
                k34++;
            }
        }
    }

    if (k34 == n * n)
    {
        cout << "(3, 4)" << endl;
    }

    // Если совпадений нет

    if (k12 < n * n & k13 < n * n & k14 < n * n & k23 < n * n & k24 < n * n & k34 < n * n)
    {
        cout << "NONE" << endl;
    }

    return 0;
}