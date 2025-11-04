#include <iostream>

using namespace std;

const char* findSubstring(const char* text, const char* word) {
    if (*word == '\0') return text;
    
    const char* text_ptr = text;
    
    while (*text_ptr != '\0') {
        const char* text_temp = text_ptr;
        const char* word_temp = word;
        
        while (*text_temp != '\0' && *word_temp != '\0' && *text_temp == *word_temp) {
            text_temp++;
            word_temp++;
        }
        
        if (*word_temp == '\0') {
            return text_ptr;
        }
        
        text_ptr++;
    }
    
    return nullptr;
}

int main() {
    const char* text = "Hello, World! Programming is fun!";
    const char* word = "World";
    
    const char* result = findSubstring(text, word);
    
    if (result != nullptr) {
        cout << "Подстрока найдена: " << result << endl;
    } else {
        cout << "Подстрока не найдена" << endl;
    }
    
    return 0;
}