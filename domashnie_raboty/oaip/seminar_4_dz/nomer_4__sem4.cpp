#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    
    // Направления движения: вправо, вниз, влево, вверх
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    int row = 0, col = 0;  // Начальная позиция
    int direction = 0;     // Начинаем движение вправо
    int num = 1;           // Первое число для заполнения
    
    while (num <= N * N) {
        matrix[row][col] = num++;
        
        // Пробуем двигаться в текущем направлении
        int next_row = row + dr[direction];
        int next_col = col + dc[direction];
        
        // Если достигли границы или уже заполненной ячейки, меняем направление
        if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N || 
            matrix[next_row][next_col] != 0) {
            direction = (direction + 1) % 4;
            next_row = row + dr[direction];
            next_col = col + dc[direction];
        }
        
        row = next_row;
        col = next_col;
    }
    
    // Вывод матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j];
            if (j < N - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}