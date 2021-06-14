#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int arr[], int n)
{
    int i, j;
    for (i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
       cout << arr[i] << " "; 
    }
    cout << endl;
}

int main()
{
    int arr[] {10,20,19,31,34,30};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array : ";
    printArray(arr, size);
    cout << "Sorted array is : ";
    bubblesort(arr, size);
    printArray(arr, size);
    return 0;
}