#include <iostream>

using namespace std;

int myStrLen(const char* str)
{
    int i = 0;
    
    while (str[i] != '\0')
    {
        ++i;
    }

    return i;
}

int main()
{
    char myStr[] = "kjhgfdsh";
    char *strPtr = myStr;

    cout << myStrLen(strPtr) << endl;

    return 0;
}