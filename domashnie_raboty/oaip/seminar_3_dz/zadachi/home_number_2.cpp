#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int maxNechet;
    int flag = 0;
    int countChet = 0;

    cout << "Введите n: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Введите число: ";
        cin >> arr[i];

        if (arr[i] % 2 == 0)
        {
            countChet++;
        }

        else if (flag == 0 && arr[i] % 2 != 0)
        {
            maxNechet = arr[i];
            flag++;
        }

        else if (arr[i] % 2 != 0 && arr[i] > maxNechet)
        {
            maxNechet = arr[i];
        }
    }

    cout << "Максимальное нечётное: " << maxNechet << ", а количество четных: " << countChet;

    return 0;
}