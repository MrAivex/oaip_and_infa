#include <iostream>
using namespace std;

int main()
{
    float min;
    int imin = 0;
    float minKey = 0;
    float max;
    int imax = 0;
    float maxKey = 0;
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

        if (arr[i] > max)
        {
            max = arr[i];
            imax = i;
        }
    }

    for (int j = 0; j < 15; j++)
    {
        cout << arr[j] << " ";
    }

    cout << endl;

    minKey = arr[0];
    maxKey = arr[14];

    arr[0] = min;
    arr[14] = max;

    arr[imin] = minKey;
    arr[imax] = maxKey;

    for (int j = 0; j < 15; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}