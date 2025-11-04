#include <iostream>
#include <cstring>

using namespace std;

void count(const char* src, const char* s)
{
    int countS = 0;
    while (*src != '\0')
    {
        if (*src == *s)
        {
            countS++;
        }

        src++;
    }

    cout << countS << endl;
}

int main()
{
    char strSrc[50] = "";
    char* ptrSrc = strSrc;
    char* s = new char;

    cout << "Введите строку: ";
    cin.getline(strSrc, 50);
    cout << "Введите символ: ";
    cin >> s; 

    count(strSrc, s);

    return 0;
}