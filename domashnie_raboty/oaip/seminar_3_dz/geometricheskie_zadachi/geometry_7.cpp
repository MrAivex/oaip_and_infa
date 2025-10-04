#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;
    cout << "Введите количество вершин: ";
    cin >> n;

    int arr[n];
    int curV = 1;

    int maxX = 0, minX = 0, maxY = 0, minY = 0;

    cout << "Введите " << n * 2 << " целых чисел" << endl;

    for (int i = 0; i < n * 2; i = i + 2)
    {
        cout << "введите координату X вершины " << curV << ": ";
        cin >> arr[i];
        cout << "введите координату Y вершины " << curV << ": ";
        cin >> arr[i + 1];
        cout << endl;
        curV++;

        if (arr[i] > maxX)
        {
            maxX = arr[i];
        }
        else if (arr[i] < minX)
        {
            minX = arr[i];
        }

        if (arr[i + 1] > maxY)
        {
            maxY = arr[i + 1];
        }
        else if (arr[i + 1] < minY)
        {
            minY = arr[i + 1];
        }
    }

    int x = 0, y = 0;
    cin >> x >> y;

    if (x > minX & x < maxX & y > minY & y < maxY)
    {
        cout << "Точка лежит внутри";
    }
    else
    {
        cout << "Точка лежит снаружи";
    }

    

    return 0;
}