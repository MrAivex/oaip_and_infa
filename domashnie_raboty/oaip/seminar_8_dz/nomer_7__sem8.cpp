#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n = 0;

    cout << "Введите n: ";
    cin >> n;

    char **arr = new char*[n];

    for (int i = 0; i < n; ++i)
    {
        *(arr + i) = new char;
        cin >> *(arr + i);
    }

    for (int i = 1; i < n; i++)
    {
        const char* s2 = *(arr + i);
        const char* s1 = *(arr + i - 1);
        cout << s1 << " " << s2 << endl;
        for (int j = i; j > 0 && strcmp(s1, s2) > 0; j--)
        {
            swap(*(arr + j - 1), *(arr + j));
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << endl;
    }

    return 0;
}
