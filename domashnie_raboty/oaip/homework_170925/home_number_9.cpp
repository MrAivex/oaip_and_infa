#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int sumN = 0;

    cout << "Введите число: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0 || i % 5 == 0) // Либо исключающее или "^", зависит от уточнения формулировки задания
        {
            sumN += i;
        }
    }

    cout << "Сумма чисел равна: " << sumN;

    return 0;
}