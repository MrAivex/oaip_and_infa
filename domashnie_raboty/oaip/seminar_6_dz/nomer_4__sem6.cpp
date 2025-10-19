#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    string b;

    bool all_found = true;

    cout << "Введите строку: ";
    cin >> a >> b;
    
    for (int i = 0; i < b.length(); i++)
    {
        char curChar = b[i];
        bool found = false;

        for (int j = 0; j < a.length(); j++)
        {
            if (curChar == a[j])
            {
                found = true;
                break;
            }
        }

        if (found == false)
        {
            all_found = false;
        }
    }

    if (all_found)
    {
        cout << "Да" << endl;
    }
    else
    {
        cout << "Нет" << endl;
    }
    
    return 0;
}