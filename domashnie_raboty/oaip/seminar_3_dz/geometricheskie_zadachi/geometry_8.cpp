#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int D1x = 0, D1y = 0;
    int D2x = 0, D2y = 0;

    cout << "Введите 4 целых числа: ";
    cin >> D1x >> D1y >> D2x >> D2y;

    int x = pow(D2x - D1x, 2), y = pow(D2y - D1y, 2);

    float r = sqrt(x + y);

    cout << r;

    return 0;
}