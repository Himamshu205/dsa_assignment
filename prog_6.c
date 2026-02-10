#include <stdio.h>

/* Swap helper */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* ---------------- MAX HEAP ---------------- */
void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        maxHeapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);
}

/* ---------------- MIN HEAP ---------------- */
void minHeapify(int a[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i) {
        swap(&a[i], &a[smallest]);
        minHeapify(a, n, smallest);
    }
}

void buildMinHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);
}

/* Print array */
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* Copy array */
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int arr[] = {3, 5, 1, 10, 2, 7, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxH[50], minH[50];
    copyArray(arr, maxH, n);
    copyArray(arr, minH, n);

    printf("Original Array: ");
    printArray(arr, n);

    buildMaxHeap(maxH, n);
    printf("Max Heap Array: ");
    printArray(maxH, n);

    buildMinHeap(minH, n);
    printf("Min Heap Array: ");
    printArray(minH, n);

    return 0;
}
