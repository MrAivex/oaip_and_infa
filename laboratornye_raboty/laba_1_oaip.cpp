#include <iostream>
using namespace std;

// Лабораторная работа по ОАиПу №1

void insertionSort(int arr[10])
{
    for (int i = 1; i < 10; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}

int main() {
	int warray[10]; // #1
	int sum = 0;
	long long int minElement = 100000000000;

	for (int i = 0; i < 10; i++) { // #2
		cout << "Введите число: ";
		cin >> warray[i];
	}

	for (int i = 0; i < 10; i++) { // #3
		cout << warray[i] << " ";
	}

	for (int i = 0; i < 10; i++) { // #4
		sum += warray[i];
	}

	cout << endl << sum << endl;

	for (int i = 0; i < 10; i++) { // #5
		if (warray[i] < minElement) {
			minElement = warray[i];
		}
	}

	for (int i = 1; i < 10; i++) {
		if (warray[i] < warray[i - 1]){

		}
	}

	cout << minElement << endl;

    insertionSort(warray);

	return 0;
}