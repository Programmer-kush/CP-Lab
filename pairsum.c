#include<stdio.h>
 #include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


void input(int arr[], int n)
{
    printf("enter %d elements in the array: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void pair_sum(int arr[],int n,int x,int *a,int *b){
    int i=0;
    int j=n-1;

    qsort(arr, n, sizeof(int), compare);

    while(i<j){
        if((arr[i]+arr[j])==x){
            printf("%d and %d\n",arr[i],arr[j]);
            return;
        }
        else if((arr[i]+arr[j])<x){
            i++;
        }
        else j--;
    }

    
    *a=0,*b=0;
    return;
}

int main(){
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    int arr[n];
    input(arr,n);

    int x;
    printf("enter x: ");
    scanf("%d",&x);
    
    int a,b;
    pair_sum(arr,n,x,&a,&b);

    
}