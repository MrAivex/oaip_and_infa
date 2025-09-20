#include <iostream>
using namespace std;

int main()
{
    char simbol = ' ';

    for (int i = 32; i <= 126; i++)
    {
        simbol = i;
        cout << "Символ: " << simbol << " имеет код: " << i << endl;
    }

    return 0;
}