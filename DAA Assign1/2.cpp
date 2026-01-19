#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    int temp[100];   

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Original Array 1: ";
    printArray(arr1, n1);
    mergeSort(arr1, 0, n1 - 1);
    cout << "Sorted Array 1:   ";
    printArray(arr1, n1);

    cout << endl;

    cout << "Original Array 2: ";
    printArray(arr2, n2);
    mergeSort(arr2, 0, n2 - 1);
    cout << "Sorted Array 2:   ";
    printArray(arr2, n2);

    return 0;
}
