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
    float srarifm = 0;

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

    if (imin == 4 && imax == 9)
    {
        srarifm = (float(min) + float(max)) / 2;
        cout << "Среднее арифметическое: " << srarifm;
    }

    return 0;
}