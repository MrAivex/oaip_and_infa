#include <iostream>
#include <random>

using namespace std;

void free2D(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}

int **transpose(int **arr, int n, int m)
{
    int **matrix = new int*[m];

    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = arr[j][i];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
        }

        cout << endl;
    }
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 99);


    int n = 0, m = 0;
    cout << "Введите количество строк и столбцов: ";
    cin >> n >> m;

    int **arr = new int*[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = dist(gen);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    transpose(arr, n, m);

    free2D(arr, n);

    return 0;
}