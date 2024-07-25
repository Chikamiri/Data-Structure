#include <stdio.h>
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    int tmp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = tmp;

    return i + 1;
}
void sort(int a[], int low, int high) {
    if (low < high) {
        int pivot = partition(a, low, high);
        sort(a, low, pivot - 1);
        sort(a, pivot + 1, high);
    }
}
int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}