#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> vec = {4, 7, 84, 75, 46, 4, 8, 0, 8, 3, 54, 9, 3, 6, 7, 2, 17, 43, 3, 2};

    auto find_seven = find(vec.begin(), vec.end(), 7);

    if (find_seven != vec.end())
    {
        cout << "Найдено число 7" << endl;
    }
    else
    {
        cout << "Not found 7" << endl;
    }

    sort(vec.begin(), vec.end());

    auto last = unique(vec.begin(), vec.end());

    for (int elem : vec)
    {
        cout << elem << " ";
    }

    return 0;
}