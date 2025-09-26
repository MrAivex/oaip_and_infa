#include <iostream>
using namespace std;

int main()
{
    float min = 0;
    int imin = 0;
    float max = 0;
    int imax = 0;
    int flag = 0;

    float arr[15];

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

        if (arr[i] < min)
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

    if (imin < imax)
    {
        cout << "Произведение максимального и минимальнго: " << min * max;
    }

    return 0;
}