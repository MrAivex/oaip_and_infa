#include <iostream>
#include <vector>

using namespace std;

int main() {
    float det = 2 * (-1) - 3 * 5;
    float det1 = 13 * (-1) - 3 * 9;
    float det2 = 2 * 9 - 13 * 5;

    float x = det1 / det;
    float y = det2 / det;

    cout << "x = " << x << endl << "y = " << y;
    
    return 0;
}