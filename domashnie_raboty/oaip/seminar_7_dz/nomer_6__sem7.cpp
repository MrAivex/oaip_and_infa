#include <iostream>
#include <cstring>

using namespace std;

void reverse(char* src)
{
    char* end = src + strlen(src) - 1;
    while (end >= src)
    {
        cout << *end;
        end--;
    }
}

int main()
{
    char strSrc[50] = "";
    char* ptrSrc = strSrc;

    cout << "Введите строку: ";
    cin.getline(strSrc, 50);

    reverse(strSrc);

    return 0;
}