#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    vector<int> davlenie;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>  gen_random_number(1, 10);

    for (int i = 0; i < 50; i++)
    {
        davlenie.push_back(gen_random_number(gen));
    }

    

    return 0;
}