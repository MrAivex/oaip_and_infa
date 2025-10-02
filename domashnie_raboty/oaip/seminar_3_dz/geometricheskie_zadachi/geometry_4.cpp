#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int arr[8];
    int curV = 1;

    cout << "Введите 8 целых чисел" << endl;

    for (int i = 0; i < 8; i = i + 2)
    {
        cout << "введите координату X вершины " << curV << ": ";
        cin >> arr[i];
        cout << "введите координату Y вершины " << curV << ": ";
        cin >> arr[i + 1];
        cout << endl;
        curV++;
    }

    double x1 = 0, y1 = 0;

    for (int i = 2; i < 8; i = i + 2)
    {
        if (arr[i] != arr[0] & arr[i + 1] != arr[1])
        {
            x1 = arr[i];
            y1 = arr[i + 1];
        }
    }

    double x = pow(x1 - arr[0], 2);
    double y = pow(y1 - arr[1], 2);
    double d = sqrt(x + y);

    cout << d;

    return 0;
}