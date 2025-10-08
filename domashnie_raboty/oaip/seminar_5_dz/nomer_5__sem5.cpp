#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<float>  vec;

    for (int i = 0; i < 6; i++)
    {
        int n = 0;
        cout << "Введите элемент вектора: ";
        cin >> n;
        vec.push_back(n);
    }

    auto minmax = minmax_element(vec.begin(), vec.end());

    float accumulate1 = accumulate(vec.begin(), vec.end(), 0) / 6;

    auto mediana = [&vec]()
    {
        float srar = 0;
        sort(vec.begin(), vec.end());
        for (int i = 0; i < 4; i++)
        {
            if (i == 2 || i == 3)
            {
                srar += vec[i];
            }
        }
        return srar / 2;
    };

    auto mediana1 = mediana(); 

    cout << *(minmax.first) << " " << *(minmax.second) << " " << accumulate1 << " " << mediana1;

    return 0;
}