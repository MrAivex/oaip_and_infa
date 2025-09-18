#include <iostream>
using namespace std;

// Лабораторная работа по инфе №1

int main() {
	// №1
	int temp;
	cout << "Введите температуру: " << endl;
	cin >> temp;
	if (temp < 0) {
		cout << "Наденьте зимнюю одежду" << endl;
	}
	if (temp >= 0 && temp <= 10) {
		cout << "Наденьте тёплую одежду" << endl;
	}
	if (temp >= 11 && temp <= 20) {
		cout << "Наденьте лёгкую одежду" << endl;
	}
	if (temp > 20) {
		cout << "Наденьте летнюю одежду" << endl;
	}

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