#include <iostream>
#include <string>
using namespace std;

string replaceSubstring(const string& str, const string& oldSub, const string& newSub) {
    string result = str;
    size_t pos = 0;
    
    while ((pos = result.find(oldSub, pos)) != string::npos) {
        result.replace(pos, oldSub.length(), newSub);
        pos += newSub.length();
    }
    
    return result;
}

int main() {
    string input, oldSub, newSub;
    
    cout << "Введите строку: ";
    getline(cin, input);
    
    cout << "Введите подстроку для замены: ";
    getline(cin, oldSub);
    
    cout << "Введите новую подстроку: ";
    getline(cin, newSub);
    
    string result = replaceSubstring(input, oldSub, newSub);
    cout << "Результат: " << result << endl;
    
    return 0;
}