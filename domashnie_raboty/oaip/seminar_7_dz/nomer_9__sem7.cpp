#include <iostream>

using namespace std;

void removeSpaces(char* str) {
    char* read_ptr = str;
    char* write_ptr = str;
    
    while (*read_ptr != '\0') {
        if (*read_ptr != ' ') {
            *write_ptr = *read_ptr;
            write_ptr++;
        }
        read_ptr++;
    }
    
    *write_ptr = '\0';
}

int main() {
    char str[] = "This is a test string with spaces";
    
    cout << "Исходная строка: " << str << endl;
    
    removeSpaces(str);
    
    cout << "Без пробелов: " << str << endl;
    
    return 0;
}