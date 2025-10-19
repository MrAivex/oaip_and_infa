#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool areAnagrams(string str1, string str2) {
    // Удаляем пробелы и приводим к нижнему регистру
    str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
    str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    // Сортируем и сравниваем
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    return str1 == str2;
}

int main() {
    string str1, str2;
    
    cout << "Введите первую строку: ";
    getline(cin, str1);
    
    cout << "Введите вторую строку: ";
    getline(cin, str2);
    
    if (areAnagrams(str1, str2)) {
        cout << "Да" << endl;
    } else {
        cout << "Нет" << endl;
    }
    
    return 0;
}