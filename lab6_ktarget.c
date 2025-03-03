//given an array in which each elemnt at which atmost k distace away from it's target position in the sorted array,sort the array in optimized time

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
} MinHeap;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;
    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapify(heap, smallest);
    }
}

int extractMin(MinHeap* heap) {
    if (heap->size == 0) return -1;

    int minValue = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return minValue;
}

void insertHeap(MinHeap* heap, int value, int capacity) {
    if (heap->size == capacity) return;

    int i = heap->size++;
    heap->data[i] = value;

    while (i > 0 && heap->data[i] < heap->data[(i - 1) / 2]) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void sortNearlySortedArray(int arr[], int n, int k) {
    MinHeap heap;
    heap.data = (int*)malloc((k + 1) * sizeof(int));
    heap.size = 0;

    for (int i = 0; i <= k && i < n; i++) {
        insertHeap(&heap, arr[i], k + 1);
    }

    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = extractMin(&heap);
        insertHeap(&heap, arr[i], k + 1);
    }

    while (heap.size > 0) {
        arr[index++] = extractMin(&heap);
    }

    free(heap.data);
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    sortNearlySortedArray(arr, n, k);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0
}
