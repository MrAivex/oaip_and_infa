#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string news;
    string num = "1234567890";
    int flag = 1;
    cout << "Введите строку: ";
    cin >> s;
    
    for (int i = 0; i < s.length(); i++)
    {
        flag = 1;

        for (int j = 0; j < num.length(); j++)
        {
            if (s[i] == num[j])
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            news += s[i];
        }
    }

    cout << news << endl;
    
    return 0;
}