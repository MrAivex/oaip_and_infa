#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec;

    for (int i = 0; i < 20; i++)
    {
        int n = 0;
        cout << "Введите число: ";
        cin >> n;
        vec.push_back(n);
    }

    auto findMax = [vec]()
    {
        return *max_element(vec.begin(), vec.end());
    };

    int max = findMax();

    cout << max;

    return 0;
}