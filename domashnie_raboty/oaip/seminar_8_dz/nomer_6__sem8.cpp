#include <iostream>
#include <random>

using namespace std;

int sumElements(int **arr, int n, int m)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += *(*(arr + i) + j);
        }
    }

    return sum;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution rand(0, 99);

    int n = 0, m = 0;

    cout << "Введите n: ";
    cin >> n;
    cout << "Введите m: ";
    cin >> n;

    int** arr = new int*[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand(gen);
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

    cout << endl;

    cout << sumElements(arr, n, m) << endl;

    return 0;
}