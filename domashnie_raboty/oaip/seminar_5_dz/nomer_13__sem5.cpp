#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    vector<int> d;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>  gen_random_number(-2, 15);

    for (int i = 0; i < 50; i++)
    {
        d.insert(d.end(), gen_random_number(gen));
    }

    for_each(d.begin(), d.end(), [](int val) { cout << val << " "; });

    cout << endl;

    d.erase(remove_if(d.begin(), d.end(), [](int val) { return val < 0 || val > 12; }), d.end());

    for_each(d.begin(), d.end(), [](int val) { cout << val << " "; });

    float mid = accumulate(d.begin(), d.end(), 0) / 50;
    auto minmax = minmax_element(d.begin(), d.end());
    int min = *(minmax.first);
    int max = *(minmax.second);

    cout << endl << mid << endl;

    cout << "min = " << min << " max = " << max << endl;

    for_each(d.begin(), d.end(), [](int val) { if (val > 8) cout << val << " "; });

    return 0;
}