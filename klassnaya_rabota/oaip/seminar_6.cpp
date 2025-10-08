#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int main()
{
    // char myString[50]; // В массиве хранится 
    // char hello[] = "Hello"; // В массиве хранится: H, e, l, l, o, \O
    // char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    // cin.getline(myString, 50);
    // cout << myString;

    const char* haystack = "Hello, World";
    const char* needle = "World";

    char* result = strstr(haystack, needle);

    if (result != nullptr)
    {
        cout << result - haystack + 1 << endl;
    }
    else
    {
        cout << "Substring not found" << endl;
    }

    return 0;
}