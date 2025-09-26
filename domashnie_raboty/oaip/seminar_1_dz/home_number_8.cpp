#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int count = 0;
    string s = "";
    string itog = "";

    cout << "Введите n ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент строки ";
        cin >> s;
        if (s == "e" || s == "y" || s == "u" || s == "i" || s == "o" || s == "a" || s == "E" || s == "Y" || s == "U" || s == "I" || s == "O" || s == "A")
        {
            count++;
        }
    }

    cout << count;

    return 0;
}