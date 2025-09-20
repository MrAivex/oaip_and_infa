#include <iostream>
using namespace std;

int main()
{
    int n = 0;

    cout << "Введите n ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << i * i << endl;
    }

    return 0;
}