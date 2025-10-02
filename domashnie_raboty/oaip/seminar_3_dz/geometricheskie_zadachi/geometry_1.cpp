#include <iostream>

using namespace std;

int main()
{
    int coords[6];
    int s = 0;
    for (int i = 0; i < 6; i++)
    {
        cout << "Введите координату: ";
        cin >> coords[i];
    }

    int x1 = coords[0], y1 = coords[1];
    int x2 = coords[2], y2 = coords[3];
    int x3 = coords[4], y3 = coords[5];

    s = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2;

    cout << s << endl;

    return 0;
}