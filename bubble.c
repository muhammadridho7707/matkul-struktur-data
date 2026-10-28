#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Elemen terbesar akan menggelembung ke ujung kanan
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar posisi jika urutan salah
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Optimasi: Jika dalam satu putaran penuh tidak ada pertukaran, berarti array sudah terurut
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int n;
    printf("BUBBLE SORT\n");
    printf("Masukkan jumlah data: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan %d angka:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Hasil pengurutan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}