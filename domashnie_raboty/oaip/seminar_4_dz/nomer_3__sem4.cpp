#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<int> row_min(N, INT_MAX);
    vector<int> row_max(N, INT_MIN);
    vector<int> col_min(M, INT_MAX);
    vector<int> col_max(M, INT_MIN);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val = matrix[i][j];
            if (val < row_min[i]) row_min[i] = val;
            if (val > row_max[i]) row_max[i] = val;
        }
    }
    
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            int val = matrix[i][j];
            if (val < col_min[j]) col_min[j] = val;
            if (val > col_max[j]) col_max[j] = val;
        }
    }
    
    bool found = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val = matrix[i][j];
            if (val == row_min[i] && val == col_max[j]) {
                cout << "A " << val << " " << i + 1 << " " << j + 1 << endl;
                found = true;
            }
            if (val == row_max[i] && val == col_min[j]) {
                cout << "B " << val << " " << i + 1 << " " << j + 1 << endl;
                found = true;
            }
        }
    }
    
    if (!found) {
        cout << "NONE" << endl;
    }
    
    return 0;
}