#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Angka yang gilirannya akan disisipkan
        int j = i - 1;

        // Geser semua elemen yang lebih besar dari key ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Sisipkan key di posisi yang tepat
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("INSERTION SORT\n");
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan %d angka:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Hasil pengurutan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}