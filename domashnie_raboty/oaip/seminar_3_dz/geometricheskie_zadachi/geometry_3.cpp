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

    double Cx = (x1 + x2 + x3) / 3;
    double Cy = (y1 + y2 + y3) / 3;

    cout << "Координаты центра масс треугольника: ( " << Cx << ", " << Cy << " )";

    return 0;
}