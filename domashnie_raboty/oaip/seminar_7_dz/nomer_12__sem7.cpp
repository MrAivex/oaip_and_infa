#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    
    cout << "Исходный вектор: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    
    int* p = vec.data();
    size_t size = vec.size();
    
    for (size_t i = 0; i < size; i++) {
        *(p + i) += 10;
    }
    
    cout << "После увеличения на 10: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}