#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string str;

    cout << "Введите строку: ";
    cin >> str;

    string str2 = str;

    for (int i = 0; i < str.length() / 2; i++)
    {
        char cur = str.at(i);
        str[i] = str[str.length() - i - 1];
        str[str.length() - i - 1] = cur;
    }

    if (str == str2)
    {
        cout << "Строка является палиндромом" << endl;
    }
    else
    {
        cout << "Строка не является палиндромом" << endl;
    }

    cout << (str == str2);

    return 0;
}