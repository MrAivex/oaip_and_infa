#include <iostream>
#include <cstring>

using namespace std;

void replace(char* src)
{
    int countS = 0;
    while (*src != '\0')
    {
        if (*src == ' ')
        {
            *src = '_';
        }

        src++;
    }
}

int main()
{
    char strSrc[50] = "";
    char* ptrSrc = strSrc;

    cout << "Введите строку: ";
    cin.getline(strSrc, 50);

    replace(strSrc);

    cout << strSrc << endl;
    return 0;
}