#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int pivot) {
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        } else if (arr[j] == pivot) {
            swap(&arr[j], &arr[high]);  
            j--; 
        }
    }
    swap(&arr[i], &arr[high]);  
    return i;
}


void matchPairs(int nuts[], int bolts[], int low, int high) {
    if (low < high) {
        // Use last bolt as pivot to partition nuts
        int pivotIndex = partition(nuts, low, high, bolts[high]);

        // Use matched nut as pivot to partition bolts
        partition(bolts, low, high, nuts[pivotIndex]);

        // Recursively match left and right parts
        matchPairs(nuts, bolts, low, pivotIndex - 1);
        matchPairs(nuts, bolts, pivotIndex + 1, high);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int nuts[] = {4, 2, 5, 1, 3};
    int bolts[] = {2, 4, 3, 5, 1};
    int n = sizeof(nuts) / sizeof(nuts[0]);

    printf("Before matching:\n");
    printf("Nuts:  "); 
    printArray(nuts, n);
    printf("Bolts: "); 
    printArray(bolts, n);

    matchPairs(nuts, bolts, 0, n - 1);

    printf("\nAfter matching:\n");
    printf("Nuts:  ");
    printArray(nuts, n);
    printf("Bolts: "); 
    printArray(bolts, n);

    return 0;
}
