#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int arr[6];
    int curV = 1;

    cout << "Введите 6 целых чисел" << endl;

    for (int i = 0; i < 6; i = i + 2)
    {
        cout << "введите координату X вершины " << curV << ": ";
        cin >> arr[i];
        cout << "введите координату Y вершины " << curV << ": ";
        cin >> arr[i + 1];
        cout << endl;
        curV++;
    }

    double x1 = arr[0], x2 = arr[2], x3 = arr[4];
    double y1 = arr[1], y2 = arr[3], y3 = arr[5];

    double product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (product == 0)
    {
        cout << "Точки лежат на одной прямой" << endl;
    }
    else
    {
        cout << "Точки не лежат на одной прямой" << endl;
    }

    return 0;
}