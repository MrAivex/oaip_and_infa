#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Введите строку: ";
    cin >> s;
    
    int count = 0;
    
    for (int i = 0; i < s.length(); i++) {
        bool is_unique = true;
        
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                is_unique = false;
                break;
            }
        }
        
        if (is_unique) {
            count++;
        }
    }
    
    cout << "Количество различных символов: " << count << endl;
    
    return 0;
}