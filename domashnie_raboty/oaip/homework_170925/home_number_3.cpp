#include <iostream>
using namespace std;

int main()
{
    float cdeg = 0;

    cout << "Введите температуру в градусах Цельсия ";
    cin >> cdeg;

    cout << "Температура в градусах Фаренгейта равна " << (cdeg * 9) / 5 + 32;

    return 0;
}