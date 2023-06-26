#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0;
    int j = 0;
    int k = 0;


    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }


    while (i < size1)
        merged[k++] = arr1[i++];


    while (j < size2)
        merged[k++] = arr2[j++];
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int merged[size1 + size2];

    mergeArrays(arr1, size1, arr2, size2, merged);

    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; i++)
        cout << merged[i] << " ";

    return 0;
}
