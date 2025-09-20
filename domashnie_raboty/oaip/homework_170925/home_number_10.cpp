#include <iostream>
using namespace std;

int main()
{
    int n = 0;

    cout << "Введите число: ";
    cin >> n;

    if (n > 0)
    {
        cout << "Число положительное";
    }
    else if (n == 0)
    {
        cout << "Число равно нулю";
    }
    else if (n < 0)
    {
        cout << "Число отрицательное";
    }

    return 0;
}