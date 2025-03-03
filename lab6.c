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
        
        int pivotIndex = partition(nuts, low, high, bolts[high]);

      
        partition(bolts, low, high, nuts[pivotIndex]);

     
        matchPairs(nuts, bolts, low, pivotIndex - 1);
        matchPairs(nuts, bolts, pivotIndex + 1, high);
    }
}

void brute_force_match(int nuts[], int bolts[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nuts[i] == bolts[j]) {
                int temp = bolts[i];
                bolts[i] = bolts[j];
                bolts[j] = temp;
                break;
            }
        }
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main() {
    int nuts[] = {0,0,0};
    int bolts[] = {0,0,0};
    int n = sizeof(nuts) / sizeof(nuts[0]);

    printf("Before matching:\n");
    printf("Nuts:  "); 
    printArray(nuts, n);
    printf("Bolts: "); 
    printArray(bolts, n);

    matchPairs(nuts, bolts, 0, n - 1);
    // brute_force_match(nuts, bolts,n);

    printf("\nAfter matching:\n");
    printf("Nuts:  ");
    printArray(nuts, n);
    printf("Bolts: "); 
    printArray(bolts, n);

    return 0;
}
