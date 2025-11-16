#include <iostream>
#include <random>

using namespace std;


int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 99);


    int n = 0, m = 0;
    cout << "Введите количество строк и столбцов: ";
    cin >> n >> m;

    int **arr = new int*[n];

    for (int i = 0; i < m; i++)
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

    return 0;
}