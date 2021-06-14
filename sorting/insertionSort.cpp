#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i;
    int key;
    int j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[]{10, 20, 30, 25, 45, 41, 19, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sorting : ";
    printArray(arr, size);
    cout << "After sorting : ";
    insertionSort(arr, size);
    printArray(arr, size);
    return 0;
}