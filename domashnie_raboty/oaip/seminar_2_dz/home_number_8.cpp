#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int min = 0;
    int imin = 0;
    int max = 0;
    int imax = 0;
    int flag = 0;

    for (int i = 0; i < 10; i++)
    {
        cout << "Введите число: ";
        cin >> arr[i];

        if (flag == 0)
        {
            min = arr[i];
            max = arr[i];
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
            imax = i;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    if (imin == 4 && imax == 1)
    {
        for (int i = imin + 1; i < 10; i++)
        {
            arr[i] = max;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}