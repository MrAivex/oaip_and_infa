#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cout << "Введите N: ";
    cin >> n;

    int matrix[n][n];

    int flagString = 1;
    int flagRow = 1;
    int flagDiagonal = 1;

    int sumString = 0;
    int sumRows = 0;


    // Ввод чисел в матрицу

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Введите число: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        int sumStringCurrent = 0;
        int sumStringFeauter = 0;

        for (int j = 0; j < n; j++)
        {
            sumStringCurrent += matrix[i][j];
            sumStringFeauter += matrix[i + 1][j];
        }
        
        if (sumStringCurrent != sumStringFeauter)
        {
            flagString = 0;
            break;
        }

        sumString = sumStringCurrent;

    }

    for (int j = 0; j < n - 1; j++)
    {
        int sumRowCurrent = 0;
        int sumRowFeauter = 0;

        for (int i = 0; i < n; i++)
        {
            sumRowCurrent += matrix[i][j];
            sumRowFeauter += matrix[i][j + 1];
        }
        
        if (sumRowCurrent != sumRowFeauter)
        {
            flagString = 0;
            break;
        }

        sumRows = sumRowCurrent;

    }

    int sumDiagonal1 = 0;
    int sumDiagonal2 = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sumDiagonal1 += matrix[i][j];
            }

            if (i == (n - 1 - j))
            {
                sumDiagonal2 += matrix[i][j];
            }
        }
    }

    if (sumDiagonal1 != sumDiagonal2)
    {
        flagDiagonal = 0;
    }

    if (sumString != sumRows)
    {
        flagString = 0;
        flagRow = 0;
    }

    if (flagString & flagRow & flagDiagonal )
    {
        cout << "Магический";
    }
    else{
        cout << "Обычный";
    }
    

    return 0;
}