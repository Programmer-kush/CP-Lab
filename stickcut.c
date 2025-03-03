
    //with each iterations subtract length of each stick by smallest stick
    //if smallest stick is 0 then remove it
    //if all sticks are removed then return
    #include <stdio.h>
    #include <stdlib.h>
    
    // Comparison function for sorting
    int compare(const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
    }
    
    void cutSticks(int arr[], int n) {
        // Step 1: Sort the array
        qsort(arr, n, sizeof(int), compare);
        
        // Step 2: Iterate and print remaining sticks after each cut
        int remaining_sticks = n;
        printf("%d\n", remaining_sticks); // Initial count of sticks
        
        for (int i = 1; i < n; i++) {
            // If there's a new minimum stick length, print remaining sticks
            if (arr[i] != arr[i - 1]) {
                remaining_sticks = n - i;
                printf("%d\n", remaining_sticks);
            }
        }
    }
    
    int main() {
        int n;
        printf("Enter number of sticks: ");
        scanf("%d", &n);
        
        int arr[n];
        printf("Enter stick lengths: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        cutSticks(arr, n);
        
        return 0;
    }
    