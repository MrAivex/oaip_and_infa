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
    vector<string> words;
    
    // Разбиваем строку на слова
    while (ss >> word) {
        words.push_back(word);
    }
    
    // Выводим слова
    cout << "Слова в строке:" << endl;
    for (const string& w : words) {
        cout << w << endl;
    }
    
    return 0;
}