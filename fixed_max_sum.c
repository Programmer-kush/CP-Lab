#include<stdio.h>
#include<limits.h>
void input(int arr[], int n)
{
    printf("enter %d elements in the array: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int optimized_sum(int arr[], int n, int k)
{

    if (n < k)
    {
        printf("Invalid input: k should be less than or equal to n\n");
        return -1;
    }

    int max_sum = 0;
    for (int i = 0; i < k; i++)
    {
        max_sum += arr[i];
    }

    int window_sum = max_sum;
    for (int i = k; i < n; i++)
    {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum)
        {
            max_sum = window_sum;
        }
    }
    return max_sum;
}

int brute_force_sum(int arr[], int n, int k) {
    int max_sum = INT_MIN;
    for (int i = 0; i <= n - k; i++) {
        int current_sum = 0;
        for (int j = 0; j < k; j++) {
            current_sum += arr[i + j];
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    return max_sum;
}


int main(){
     int n,k;
    printf("enter size of the array: ");
    scanf("%d", &n);
    int arr[n];
    input(arr, n);

    printf("enter K: ");
    scanf("%d",&k);

    //int max = optimized_sum(arr, n,k);
    int max = brute_force_sum(arr, n,k);
    printf("max sum is %d\n", max);
    return 0;


}