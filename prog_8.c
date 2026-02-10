#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static long long comparisons = 0;

int cmpCount(const void *a, const void *b) {
    comparisons++;
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

void printSmart(int a[], int n) {
    if (n <= 100) {
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");
    } else {
        for (int i = 0; i < 50; i++) printf("%d ", a[i]);
        printf("... ");
        for (int i = n - 50; i < n; i++) printf("%d ", a[i]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter N: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *a = (int*)malloc(n * sizeof(int));
    if (!a) return 0;

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) a[i] = (rand() % 1000) + 1;

    printf("\nBefore:\n");
    printSmart(a, n);

    qsort(a, n, sizeof(int), cmpCount);

    printf("\nAfter:\n");
    printSmart(a, n);

    printf("\nTotal Comparisons: %lld\n", comparisons);
    printf("Swaps/Moves: N/A (qsort)\n");

    free(a);
    return 0;
}
