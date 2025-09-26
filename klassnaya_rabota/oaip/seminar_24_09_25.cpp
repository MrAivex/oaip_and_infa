#include <iostream>
using namespace std;

int main()
{
    int rows = 3, cols = 4;
    double cl[rows][cols] = 
    {
        {0.4, 0.5, 0.8, 0.7},
        {0.3, 0.8, 1.1, 4.5},
        {0.9, 4.9, 7.0, 5.7}
    };

    double p = cl[0][0];

    cout << p;

    return 0;
}