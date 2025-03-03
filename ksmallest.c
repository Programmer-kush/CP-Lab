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

void ksmall(int arr[],int n,int k){
    
}
int main(){
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    int arr[n];
    input(arr,n);

    int k;
    printf("enter k: ");
    scanf("%d",&k);
    


    
}