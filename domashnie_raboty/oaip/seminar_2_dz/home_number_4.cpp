#include <iostream>
using namespace std;

int main()
{
    int number = 0;

    cout << "Введите число ";
    cin >> number;

    if (number % 2 == 0)
    {
        cout << "Четное";
    } 
    else
    {
        cout << "Нечетное";
    }

    return 0;
}