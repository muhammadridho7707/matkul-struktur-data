#include <stdio.h>

// Fungsi untuk menggabungkan dua sub-array yang sudah terurut
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Ukuran sub-array kiri
    int n2 = right - mid;    // Ukuran sub-array kanan

    // Buat array penampung sementara (Inilah kenapa ruangnya O(n))
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Pointer i untuk L, j untuk R, k untuk array utama
    int i = 0, j = 0, k = left;

    // Bandingkan dan seleksi angka yang terkecil dari L atau R
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Jika ada sisa di L, salin ke array utama
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Jika ada sisa di R, salin ke array utama
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi rekursif untuk membelah array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);      // Belah bagian kiri
        mergeSort(arr, mid + 1, right); // Belah bagian kanan

        merge(arr, left, mid, right);   // Gabungkan kembali
    }
}

int main() {
    int n;
    printf("MERGE SORT\n");
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan %d angka:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Hasil pengurutan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}