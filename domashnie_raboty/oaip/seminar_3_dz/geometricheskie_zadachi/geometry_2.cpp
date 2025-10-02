#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;
    int curV = 1;
    cout << "Введите количество вершин: " << endl;
    cin >> n;
    int arr[n * 2];

    cout << "Введите " << n * 2 << " целых чисел" << endl;

    for (int i = 0; i < n * 2; i = i + 2)
    {
        cout << "введите координату X вершины " << curV << ": ";
        cin >> arr[i];
        cout << "введите координату Y вершины " << curV << ": ";
        cin >> arr[i + 1];
        cout << endl;
        curV++;
    }

    double p = 0;
    int x = 0, y = 0;
    double r = 0;

    for (int i = 0; i < n * 2 - 2; i = i + 2)
    {
        x = pow(arr[i + 2] - arr[i], 2);
        y = pow(arr[i + 3] - arr[i + 1], 2);
        r = sqrt(x + y);
        p = p + r;
    }

    x = pow(arr[0] - arr[n * 2 - 2], 2);
    y = pow(arr[1] - arr[n * 2 - 1], 2);
    r = sqrt(x + y);
    p = p + r;

    cout << p << endl;

    return 0;
}