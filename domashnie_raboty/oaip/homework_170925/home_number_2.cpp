#include <iostream>
using namespace std;

int main()
{
    int lenght = 0;
    int width = 0;

    cout << "Введите длину " << endl;
    cin >> lenght;

    cout << "Введите ширину " << endl;
    cin >> width;

    cout << "Площадь прямоугольника " << lenght * width << endl;

    return 0;
}