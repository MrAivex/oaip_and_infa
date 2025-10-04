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

    bool A = (arr[0] < arr[6] & arr[2] > arr[4] & arr[1] > arr[5] & arr[3] < arr[7]);
    bool B = (arr[0] < arr[6] & arr[2] > arr[4] & arr[1] < arr[5] & arr[3] > arr[7]);

    if (A || B)
    {
        cout << "Отрезки пересекаются";
    }
    else
    {
        cout << "Отрезки не пересекаются";
    }

    

    return 0;
}