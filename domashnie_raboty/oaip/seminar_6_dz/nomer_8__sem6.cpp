#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string correctCase(const string& text) {
    string result = text;
    bool newSentence = true;
    
    for (int i = 0; i < result.length(); i++) {
        if (newSentence && isalpha(result[i])) {
            result[i] = toupper(result[i]);
            newSentence = false;
        } else {
            result[i] = tolower(result[i]);
        }

        if (result[i] == '.' || result[i] == '!' || result[i] == '?') {
            newSentence = true;
        }
    }
    
    return result;
}

int main() {
    string input;
    cout << "Введите текст: ";
    getline(cin, input);
    
    string corrected = correctCase(input);
    cout << "Исправленный текст: " << corrected << endl;
    
    return 0;
}