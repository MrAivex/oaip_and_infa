#include <iostream>
using namespace std;

int main()
{
    int number = 0;

    cout << "Введите число ";
    cin >> number;

    if (number % 15 == 0)
    {
        cout << "Делится и на 3, и на 5";
    }

    if (number % 3 == 0 && number % 5 != 0)
    {
        cout << "Делится на 3, но не делится на 5";
    }

    if (number % 3 != 0 && number % 5 == 0)
    {
        cout << "Не делится на 3, но делится на 5";
    }

    if (number % 3 != 0 && number % 5 != 0)
    {
        cout << "Не делится на 3 и на 5";
    }

    return 0;
}