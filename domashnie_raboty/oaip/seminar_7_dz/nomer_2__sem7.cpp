#include <iostream>

using namespace std;

void myStrCopy(char* dest, const char* src)
{
    int i = 0;

    while (*src != '\0')
    {
        *dest = *src;
        ++src;
        ++dest;
    }
}

int main()
{
    char string[] = "Hello, World!";
    char destination[50];

    myStrCopy(destination, string);

    cout << string << endl << destination << endl;

    return 0;
}