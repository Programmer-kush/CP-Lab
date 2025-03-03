#include <stdio.h>
#include<limits.h>

void input(int arr[], int n)
{
    printf("enter %d elements in the array: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int brute_sum(int arr[], int n,int *start_index,int *end_index)
{
    int prevsum = arr[0];
    int currsum = 0;
    int maxsum =INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currsum = 0;
        int j = 0;
        while (i + j < n)
        {
            currsum += arr[i + j];
            if (maxsum < currsum)
            {
                *start_index=i,*end_index=i+ j;
                maxsum = currsum;
            }
            j++;
        }   
    }

        int dummy=*start_index;
        while(arr[dummy]==0){
             dummy+=1;
        }
        if(dummy<n)*start_index=dummy;
        return maxsum;
}


int kadane_sum(int arr[], int n, int *start_index, int *end_index)
{
    int max_sum = INT_MIN, current_sum = 0;
    int temp_start = 0;

    for (int i = 0; i < n; i++)
    {
        current_sum += arr[i];

        if (max_sum < current_sum)
        {
            max_sum = current_sum;
            *start_index = temp_start;
            *end_index = i;
        }

        if (current_sum < 0)
        {
            current_sum = 0;
            temp_start = i+1;
        }
    }
     int dummy=*start_index;
        while(arr[dummy]==0){
             dummy+=1;
        }
        if(dummy<n)*start_index=dummy;
        
     return max_sum;
}

int main()
{
    int n;
    printf("enter size of the array: ");
    scanf("%d", &n);
    int arr[n];

    input(arr, n);
    int start_index,end_index;
    // int max = brute_sum(arr, n,&start_index,&end_index);
        int max = kadane_sum(arr, n,&start_index,&end_index);
    //int max = optimized(arr, n);
    printf("max sum is %d\n", max);
    printf("start index: %d\nend index: %d",start_index,end_index);
}


// int optimized(int arr[],int n)
// {
//     int cum_sum=0;
//     int max_sum=0;

//      for(int i=0;i<n;i++){
//             cum_sum+=arr[i];
//             if(cum_sum<0){
//                 cum_sum=0;
//             }
//             if(max_sum<cum_sum)
//             {
//                 max_sum=cum_sum;
//             }
//      }

//         return max_sum;

// }