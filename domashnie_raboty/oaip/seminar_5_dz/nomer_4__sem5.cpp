#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>  vec = {1, -3, 4, 7, 47, -9, 0, -46, 59, 3, -2};

    auto rm_otric = [&vec]()
    {
        vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x < 0; }), vec.end());
    };

    rm_otric();

    for (int elem : vec) cout << elem << " ";

    return 0;
}