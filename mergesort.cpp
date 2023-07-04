#include<bits/stdc++.h>
using namespace std;

void Merge(int *a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = a[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }

    while (i < n1) {
        a[k++] = L[i++];
    }

    while (j < n2) {
        a[k++] = R[j++];
    }


}

void mergeSort(int *a, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        Merge(a, left, mid, right);
    }
}

void printList(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n = 5000;

    srand(time(0));

    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        a[i] = (rand() % 1001);
    }

    cout << "Original array:\n";
    printList(a, n);

    mergeSort(a, 0, n - 1);

   cout<<"\n\n\n\n";
    printList(a, n);



    return 0;
}
