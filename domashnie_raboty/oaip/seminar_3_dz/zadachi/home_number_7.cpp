#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int min = 0;
    int max = 0;
    int imin = 0;
    int flag = 0;

    for (int i = 0; i < 15; i++)
    {
        cout << "Введите число: ";
        cin >> arr[i];

        if (flag == 0)
        {
            max = arr[i];
            min = arr[i];
            flag++;
        }

        else if (arr[i] < min)
        {
            min = arr[i];
            imin = i;
        }

        else if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    if (min == 0 || max == 0)
    {
        for (int i = 0; i < imin; i++)
        {
            arr[i] = 0;
        }
    }

    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}