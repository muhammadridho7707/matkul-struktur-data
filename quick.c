#include <stdio.h>

// Fungsi untuk menukar isi dua variabel
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Fungsi partisi: menempatkan pivot, angka kecil di kiri, angka besar di kanan
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Memilih elemen paling ujung kanan sebagai pivot
    int i = (low - 1);     // Pointer Penjaga batas (menandai wilayah angka kecil)

    for (int j = low; j <= high - 1; j++) {
        // Pointer Penjelajah (j) mencari angka yang lebih kecil dari pivot
        if (arr[j] < pivot) {
            i++; // Perluas wilayah angka kecil
            swap(&arr[i], &arr[j]); // Tukar angka tersebut dengan penjaga batas
        }
    }
    // Terakhir, letakkan pivot di posisi sesungguhnya
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Kembalikan posisi akhir si pivot
}

// Fungsi rekursif Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Ulangi proses untuk kubu kiri dan kubu kanan
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("QUICK SORT\n");
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan %d angka:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Hasil pengurutan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}