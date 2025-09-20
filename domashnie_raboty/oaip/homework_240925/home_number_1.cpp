#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 0;
    int count = 0;
    cout << "Введите количество элементов последовательности: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Введите число: ";
        cin >> arr[i];

        if (arr[i] > pow(2, i + 1))
        {
            count++;
        }
    }

    cout << "Количество элементов удовлетворяющих условию: " << count;

    return 0;
}