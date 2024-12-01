#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateArray(int arr[], int size, int min, int max, int index = 0) {
    if (index < size) {
        arr[index] = rand() % (max - min + 1) + min;
        generateArray(arr, size, min, max, index + 1);
    }
}

void printArray(int arr[], int size, int index = 0) {
    if (index < size) {
        cout << setw(4) << arr[index];
        printArray(arr, size, index + 1);
    }
    else {
        cout << endl;
    }
}

int countPositiveNotMultipleOf5(int arr[], int size, int index = 0) {
    if (index >= size) return 0;
    return (arr[index] > 0 && index % 5 != 0) + countPositiveNotMultipleOf5(arr, size, index + 1);
}

int sumPositiveNotMultipleOf5(int arr[], int size, int index = 0) {
    if (index >= size) return 0;
    return (arr[index] > 0 && index % 5 != 0 ? arr[index] : 0) + sumPositiveNotMultipleOf5(arr, size, index + 1);
}

void replaceWithZero(int arr[], int size, int index = 0) {
    if (index >= size) return;
    if (arr[index] > 0 && index % 5 != 0) {
        arr[index] = 0;
    }
    replaceWithZero(arr, size, index + 1);
}

int main() {
    srand(time(0));

    const int size = 20;
    int arr[size];

    generateArray(arr, size, -20, 50);

    cout << "Original array:\n";
    printArray(arr, size);

    int count = countPositiveNotMultipleOf5(arr, size);
    int sum = sumPositiveNotMultipleOf5(arr, size);

    cout << "\nProcessed array:\n";
    replaceWithZero(arr, size);
    printArray(arr, size);

    cout << "\nResults:\n";
    cout << left << setw(42) << "Count of elements matching the criterion:" << setw(5) << count << endl;
    cout << left << setw(40) << "Sum of elements matching the criterion:" << setw(5) << sum << endl;

    return 0;
}
