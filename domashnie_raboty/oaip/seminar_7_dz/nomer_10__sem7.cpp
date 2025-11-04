#include <iostream>

using namespace std;

int myStrCmp(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    
    return *s1 - *s2;
}

int main() {
    const char* str1 = "apple";
    const char* str2 = "apple";
    const char* str3 = "banana";
    
    cout << "Сравнение '" << str1 << "' и '" << str2 << "': " << myStrCmp(str1, str2) << endl;
    cout << "Сравнение '" << str1 << "' и '" << str3 << "': " << myStrCmp(str1, str3) << endl;
    cout << "Сравнение '" << str3 << "' и '" << str1 << "': " << myStrCmp(str3, str1) << endl;
    
    return 0;
}