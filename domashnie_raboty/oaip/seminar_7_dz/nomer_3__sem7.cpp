#include <iostream>
#include <cstring>

using namespace std;

void myStrCat(char* dest, const char* src)
{
    dest += strlen(dest);

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

int main()
{
    char strDest[100] = "";
    char* ptrDest = strDest;
    char strSrc[50] = "";
    char* ptrSrc = strSrc;

    cout << "Введите две строки: ";
    cin.getline(strDest, 50);
    cin.getline(strSrc, 50);

    myStrCat(ptrDest, ptrSrc);

    cout << strDest << endl;

    return 0;
}