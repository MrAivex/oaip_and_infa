#include <iostream>
using namespace std;

int main()
{
    float arr[15];
    float min = 0;
    int imin = 0;
    float max = 0;
    int imax = 0;
    int flag = 0;

    for (int i = 0; i < 15; i++)
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

    if (imin == 1 && imax == 0)
    {
        for (int j = 0; j < 15; j++)
        {
            arr[j] = arr[j] / 2;
            cout << arr[j] << " ";
        }
    }

    return 0;
}