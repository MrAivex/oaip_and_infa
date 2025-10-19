#include <iostream>
#include <string>
using namespace std;

string caesarCipher(const string& text, int shift) {
    string result = "";
    
    for (char c : text) {
        if (isupper(c)) {
            result += (c - 'A' + shift) % 26 + 'A';
        } else if (islower(c)) {
            result += (c - 'a' + shift) % 26 + 'a';
        } else {
            result += c;
        }
    }
    
    return result;
}

int main() {
    string text;
    int shift;
    
    cout << "Текст: ";
    getline(cin, text);
    
    cout << "Сдвиг: ";
    cin >> shift;

    shift = shift % 26;
    if (shift < 0) {
        shift += 26; 
    }
    
    string encrypted = caesarCipher(text, shift);
    cout << "Зашифрованный текст: " << encrypted << endl;
    
    return 0;
}