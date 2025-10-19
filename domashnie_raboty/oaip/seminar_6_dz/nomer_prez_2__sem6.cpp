#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    char symbol;
    
    cout << "Введите строку: ";
    getline(cin, input);
    
    cout << "Введите символ для удаления: ";
    cin >> symbol;
    
    string result = "";
    for (char c : input) {
        if (c != symbol) {
            result += c;
        }
    }
    
    cout << "Результат: " << result << endl;
    
    return 0;
}