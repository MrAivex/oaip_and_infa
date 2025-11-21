#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution rand(0, 99);

    int n = 0, m = 0;

    cout << "Введите n и m";
    cin >> n >> m;

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

    for (int i = 1; i < n; i++)
    {
        int sumI = 0;
        int sumI_1 = 0;
        for (int k = 0; k < m; k++)
        {
            sumI += arr[i][k];
            sumI_1 += arr[i - 1][k];
        }

        for (int j = i; j > 0 && sumI_1 > sumI; j--)
        {
            swap(arr[j - 1], arr[j]);
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