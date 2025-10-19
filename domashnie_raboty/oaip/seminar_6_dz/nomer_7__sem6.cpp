#include <iostream>
#include <string>
using namespace std;

string rleCompress(const string& str) {
    if (str.empty()) return "";
    
    string result = "";
    int count = 1;
    char current = str[0];
    
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == current) {
            count++;
        } else {
            result += current + to_string(count);
            current = str[i];
            count = 1;
        }
    }
    
    result += current + to_string(count);
    return result;
}

int main() {
    string input;
    cout << "Введите строку для сжатия: ";
    cin >> input;
    
    string compressed = rleCompress(input);
    cout << "Сжатая строка: " << compressed << endl;
    
    return 0;
}