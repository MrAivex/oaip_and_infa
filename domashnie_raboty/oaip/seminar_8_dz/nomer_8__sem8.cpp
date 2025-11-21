#include <iostream>

using namespace std;

double **allocatePlate(int n, int m)
{
    double** newPlate = new double*[n];

    for (int i = 0; i < n; ++i)
    {
        newPlate[i] = new double[m];
    }
}

void freePlate(double **plate, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] *(plate + i);
    }
    
    delete[] plate;
}

void updateTemperature(double **plate, int n, int m)
{
    double** newP = allocatePlate(n, m);
}

int main()
{
    int n = 0, m = 0;

    cout << "Введите n: ";
    cin >> n;
    cout << "Введите m: ";
    cin >> n;

    double** plate = new double*[n];



    return 0;
}