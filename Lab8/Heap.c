#include <stdio.h>
#include <stdlib.h>
// Create max heap
// Remove largest element
// Place elemenent in sorted partition

// Build max heap
// Swap root with last element
// Remove last root then heapify

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Return element at index i to
// correct pos in heap
void heapify(int a[], int n, int i) {
    int lmax = i;           // Create root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If root's children are greater than root
    // Swap root with largest child
    if (left < n && a[left] > a[lmax]) {
        lmax = left;
    }
    if (right < n && a[right] > a[lmax]) {
        lmax = right;
    }
    // If root is not largest
    if (lmax != i) {
        swap(&a[i], &a[lmax]);
        heapify(a, n, lmax);
    }
}
void sort(int a[], int n) {
    // Build
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Remove largest element
    for (int i = n - 1; i > 0; i--) {
        // Swap root with last element of unsorted array
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}