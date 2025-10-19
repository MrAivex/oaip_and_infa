#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);
    
    stringstream ss(input);
    string word;
    string longestWord = "";
    
    while (ss >> word) {
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    
    if (!longestWord.empty()) {
        cout << "Самое длинное слово: " << longestWord << endl;
    } else {
        cout << "Строка пуста!" << endl;
    }
    
    return 0;
}