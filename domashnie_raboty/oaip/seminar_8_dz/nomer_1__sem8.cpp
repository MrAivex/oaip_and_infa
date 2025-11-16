#include <iostream>

using namespace std;

void swapPointers(int **a, int **b)
{
    int *c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;

    cout << p1 << " " << *p1 << endl;
    cout << p2 << " " << *p2 << endl;

    swapPointers(&p1, &p2);

    cout << p1 << " " << *p1 << endl;
    cout << p2 << " " << *p2 << endl;

    return 0;
}