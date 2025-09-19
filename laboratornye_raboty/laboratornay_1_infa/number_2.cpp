#include <iostream>
using namespace std;

// Лабораторная работа по инфе №1

int main() {

	// №2
	int n = 0; // количество остановок
		int sum = 0; // стоимость проезда
		cout << "Введите количество остановок: " << endl;
		cin >> n;
		for (int i = 0; i < n; i++) {
			sum += 5;
		}
		cout << "Общая стоимость проезда: " << sum << endl;
	return 0;
}