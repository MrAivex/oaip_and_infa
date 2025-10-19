#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

void printUniqueSubstrings(const string& str, int k) {
    if (k > str.length()) {
        cout << "k больше длины строки!" << endl;
        return;
    }
    
    cout << "Подстроки длины " << k << " с уникальными символами:" << endl;
    
    for (int i = 0; i <= str.length() - k; i++) {
        string substring = str.substr(i, k);
        unordered_set<char> chars;
        bool isUnique = true;
        
        // Проверяем уникальность символов
        for (char c : substring) {
            if (chars.count(c)) {
                isUnique = false;
                break;
            }
            chars.insert(c);
        }
        
        if (isUnique) {
            cout << substring << endl;
        }
    }
}

int main() {
    string input;
    int k;
    
    cout << "Введите строку: ";
    cin >> input;
    cout << "Введите k: ";
    cin >> k;
    
    printUniqueSubstrings(input, k);
    
    return 0;
}