#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

// Функция для вычисления ориентации трех точек
int orientation(const Point& p, const Point& q, const Point& r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // коллинеарны
    return (val > 0) ? 1 : 2; // 1 - по часовой, 2 - против часовой
}

// Функция для проверки, лежит ли точка q на отрезке pr
bool onSegment(const Point& p, const Point& q, const Point& r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) {
        return true;
    }
    return false;
}

// Функция для проверки пересечения двух отрезков (p1,q1) и (p2,q2)
bool doIntersect(const Point& p1, const Point& q1, const Point& p2, const Point& q2) {
    // Вычисляем ориентации для всех комбинаций
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    
    // Общий случай: ориентации разные
    if (o1 != o2 && o3 != o4) {
        return true;
    }
    
    // Специальные случаи (точки коллинеарны)
    // p2 лежит на отрезке p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    // q2 лежит на отрезке p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    // p1 лежит на отрезке p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    // q1 лежит на отрезке p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    
    return false;
}

// Функция для проверки пересечения двух многоугольников
bool polygonsIntersect(const vector<Point>& poly1, const vector<Point>& poly2) {
    int n1 = poly1.size();
    int n2 = poly2.size();
    
    // Проверяем каждую сторону первого многоугольника с каждой стороной второго
    for (int i = 0; i < n1; i++) {
        int next_i = (i + 1) % n1;
        
        for (int j = 0; j < n2; j++) {
            int next_j = (j + 1) % n2;
            
            // Если найдено пересечение сторон, возвращаем true
            if (doIntersect(poly1[i], poly1[next_i], poly2[j], poly2[next_j])) {
                return true;
            }
        }
    }
    
    return false;
}

// Функция для ввода многоугольника
vector<Point> inputPolygon(const string& name) {
    int n;
    cout << "Введите количество вершин многоугольника " << name << ": ";
    cin >> n;
    
    vector<Point> polygon;
    cout << "Введите координаты вершин (x y) для " << name << ":" << endl;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        polygon.push_back(Point(x, y));
    }
    return polygon;
}

int main() {
    cout << "Проверка пересечения двух многоугольников" << endl;
    cout << "=========================================" << endl;
    
    // Ввод первого многоугольника
    vector<Point> poly1 = inputPolygon("A");
    
    // Ввод второго многоугольника
    vector<Point> poly2 = inputPolygon("B");
    
    // Проверка пересечения
    if (polygonsIntersect(poly1, poly2)) {
        cout << "Многоугольники ПЕРЕСЕКАЮТСЯ" << endl;
    } else {
        cout << "Многоугольники НЕ ПЕРЕСЕКАЮТСЯ" << endl;
    }
    
    // Демонстрационные примеры
    cout << endl << "Демонстрационные примеры:" << endl;
    
    // Пример 1: Пересекающиеся прямоугольники
    vector<Point> rect1 = {Point(0,0), Point(0,4), Point(4,4), Point(4,0)};
    vector<Point> rect2 = {Point(2,2), Point(2,6), Point(6,6), Point(6,2)};
    cout << "Пример 1: " << (polygonsIntersect(rect1, rect2) ? "Пересекаются" : "Не пересекаются") << endl;
    
    // Пример 2: Непересекающиеся прямоугольники
    vector<Point> rect3 = {Point(0,0), Point(0,2), Point(2,2), Point(2,0)};
    vector<Point> rect4 = {Point(3,3), Point(3,5), Point(5,5), Point(5,3)};
    cout << "Пример 2: " << (polygonsIntersect(rect3, rect4) ? "Пересекаются" : "Не пересекаются") << endl;
    
    // Пример 3: Многоугольники с общей вершиной
    vector<Point> poly3 = {Point(0,0), Point(0,3), Point(3,3)};
    vector<Point> poly4 = {Point(3,3), Point(3,0), Point(0,0)};
    cout << "Пример 3: " << (polygonsIntersect(poly3, poly4) ? "Пересекаются" : "Не пересекаются") << endl;
    
    return 0;
}