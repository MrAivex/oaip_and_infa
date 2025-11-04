#include <iostream>
#include <cstring>

using namespace std;

void isPalindrom(char* src, char* ptrPal)
{
    char* end = src + strlen(src) - 1;
    while (end >= src)
    {
        *ptrPal = *end;
        end--;
        ptrPal++;
    }

    src += strlen(src);
    *src = '\0'; 
    ptrPal += strlen(ptrPal);
    *ptrPal = '\0';
}

int main()
{
    char strSrc[50] = "";
    char* ptrSrc = strSrc;
    char pal[50] = "";
    char* ptrPal = pal;

    cout << "Введите строку: ";
    cin.getline(strSrc, 50);

    isPalindrom(ptrSrc, ptrPal);

    if (strcmp(strSrc, pal) == 0)
    {
        cout << "Палиндром" << endl;
    }
    else
    {
        cout << "Не палиндром" << endl;
    }

    cout << strSrc << " | " << pal << endl;

    return 0;
}