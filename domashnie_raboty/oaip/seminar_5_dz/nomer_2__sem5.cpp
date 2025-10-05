#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> myVector;

    for (int i = 0; i < 10; i++)
    {
        myVector.push_back(i);
    }

    auto coutVector = [&myVector]()
    {
        for (int elem : myVector)
        {
            cout << elem * 2 << " ";
        }
    };

    coutVector();

    return 0;
}