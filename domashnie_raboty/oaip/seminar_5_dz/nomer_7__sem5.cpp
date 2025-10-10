#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<double> vec = {4, 7, 84, 75, 46, 4, 8, 0, 8, 3, 54, 9, 3, 6, 7, 2, - 17, 43, 3, 2};

    int flag = 0;

    auto iter = remove_if(vec.begin(), vec.end(), [](double it) { return (it < -50) || (it > 50); });

    auto sred = accumulate(vec.begin(), vec.end(), 0) / 20;

    auto minmax = minmax_element(vec.begin(), vec.end());

    for (double elem : vec)
    {
        if (elem <= -10)
        {
            flag++;
        }
    }

    if (flag == 0)
    {
        cout << "Все эелементы превышают -10" << endl;
    }
    else
    {
        cout << "Не все эелементы превышают -10" << endl;
    }

    for (double elem : vec)
    {
        cout << elem << " ";
    }

    return 0;
}