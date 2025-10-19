#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s); 
    
    int vowels = 0;    
    int consonants = 0; 
    
    string vowel_letters = "aeiouy";
    
    for (char c : s) {

        char lower_c = tolower(c);
        
        if (isalpha(lower_c)) {
            if (vowel_letters.find(lower_c) != string::npos) {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    cout << "Гласных: " << vowels << endl;
    cout << "Согласных: " << consonants << endl;
    
    return 0;
}