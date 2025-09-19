#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int min;

    for (int i = 0; i < 10; i++)
    {
        cout << "Введите число: ";
        cin >> arr[i];

        if (i == 0)
        {
            min = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << "Минимальное число в массиве: " << min;

    return 0;
}