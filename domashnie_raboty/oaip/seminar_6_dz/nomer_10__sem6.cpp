#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

string reverseWords(const string& text) {
    stringstream ss(text);
    string word;
    string result = "";
    
    while (ss >> word) {
        reverse(word.begin(), word.end());
        result += word + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }
    
    return result;
}

int main() {
    string input;
    cout << "Введите предложение: ";
    getline(cin, input);
    
    string reversed = reverseWords(input);
    cout << "Результат: " << reversed << endl;
    
    return 0;
}