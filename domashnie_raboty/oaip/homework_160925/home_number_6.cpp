#include <iostream>
using namespace std;

int main()
{
    int age = 0;

    cout << "Введите возраст ";
    cin >> age;

    if (age < 18)
    {
        cout << "Вам меньше 18 лет";
    }

    if (age >= 18 && age <= 60)
    {
        cout << "Вам от 18 до 60 лет";
    }

    if (age > 60)
    {
        cout << "Вам больше 60 лет";
    }

    return 0;
}