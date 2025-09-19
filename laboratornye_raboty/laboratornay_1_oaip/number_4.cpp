#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int sum = 0;

    for (int i = 0; i < 10; i++)
    {
        cout << "Введите число: ";
        cin >> arr[i];

        sum += arr[i];
    }

    cout << "Сумма элементов массива равна: " << sum;

    return 0;
}