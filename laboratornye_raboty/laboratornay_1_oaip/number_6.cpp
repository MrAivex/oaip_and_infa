#include <iostream>
using namespace std;

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
	int arr[10];
	int sum = 0;
	long long int minElement = 100000000000;

	for (int i = 0; i < 10; i++)
    {
		cout << "Введите число: ";
		cin >> arr[i];
	}

    insertionSort(arr);

	return 0;
}