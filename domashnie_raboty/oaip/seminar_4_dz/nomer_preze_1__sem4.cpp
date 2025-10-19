#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    vector<float> det;

    cout << "Введите 6 целых чисел: " << endl;

    for (int i = 0; i < 6; i++)
    {
        float n = 0;

        cin >> n;

        det.insert(det.end(), n);
    }

    for (int i = 4; i >= 0; i -= 2)
    {
        det.insert(det.end() - i, 1);
    }

    for_each(det.begin(), det.end(), [](float val) { cout << val << " "; });

    float A = det[0] * (det[4] * det[8] - det[5] * det[7]);
    float B = -1 * det[1] * (det[3] * det[8] - det[5] * det[6]);
    float C = det[2] * (det[3] * det[7] - det[4] * det[6]);

    float s = 0.5 * (A + B + C);

    cout << endl << s;

    return 0;
}
