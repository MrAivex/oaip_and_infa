#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto create_multiplier(int factor)
    {
        return [factor](int value) { return value * factor; };
    }

int main()
{
    // vector myVector = {1, 2, 3, 4, 5};
    // iterator itBegin = myVector.begin();
    // iterator itEnd = myVector.end();

    // лямбда функции

    // auto greet = []()
    // {
    //     cout << "Hello, world!" <<endl;
    // };

    // greet();

    // double threshold = 10.0;
    // auto pred = [threshold](double h)
    // {
    //     return h < threshold;
    // };

    // if (pred(1.0))
    // {
    //     cout << "Ваше число меньше";
    // }
    // else
    // {
    //     cout << "Ваше число больше";
    // }

    // int a = 5, b = 10;

    // auto sum = [=](){return a + b;};

    // cout << sum() << endl;

    // int a = 5, b = 10;
    // auto modify = [&a, &b](){a += 10; b *= 2;};

    // modify();

    // cout << a << b << endl;

    // int a = 5, b = 10;
    // auto func = [a, &b]() {return a + b;};
    // b = 20;
    // cout << func() << endl;

    // vector vec = {5, 2, 8, 1, 3};
    // sort(vec.begin(), vec.end());

    // for (int num : vec)
    // {
    //     cout << num << " ";
    // }

    // auto multiply_by_5 = create_multiplier(5);
    // cout << multiply_by_5(3) << endl;

    vector<double> v = {10.7, 20.8, 30, 40, 50};

    auto it = find(v.begin(), v.end(), 30);
    if (it != v.end())
    {
        cout << *it << " " << (it - v.begin()) << endl;
    }

    return 0;
}