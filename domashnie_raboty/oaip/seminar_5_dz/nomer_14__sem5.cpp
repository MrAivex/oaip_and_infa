#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    vector<int> p;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>  gen_random_number(100, 500);

    for (int i = 0; i < 24; i++)
    {
        p.insert(p.end(), gen_random_number(gen));
    }

    for_each(p.begin(), p.end(), [](int val) { cout << val << " "; });

    int sum = accumulate(p.begin(), p.end(), 0);
    float mid = accumulate(p.begin(), p.end(), 0) / 24;

    int max = *max_element(p.begin(), p.end());

    cout << endl << sum << " " << mid << " " << max << endl;

    sort(p.begin(), p.end());

    for_each(p.begin(), p.begin() + 5, [](int val) { cout << val << " "; });

    return 0;
}