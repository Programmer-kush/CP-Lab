/*
Que2: you are given an array a[i] of stock price on each day find span s[i] for each a[i] the span s[i] of the stock price on a given day i 
is defined as the maximum number of consecutive days just before the given day for which price of stock on that day
is less than or equal to price on the given day,(current day also included)
*/

#include<stdio.h>
#include<stdlib.h>

void brute_stock(int A[],int n,int S[]){
        for(int i=1;i<n;i++){   //--->O(n-1)
            for(int j=i;j>=0;j--){  // --->O(i)
                if(A[j]<=A[i]){
                    S[i]++;
                }
                else break;
            }
        }
}

// void optimized_stock(int A[],int n,int S[]){        
//     S[0]=1;
//     for(int i=1;i<n;i++){       //--->O(n)
//          if(A[i-1]<=A[i]){
//                     S[i]=S[i-1]+1;
//                 }
//     }
//     return;
// }

// void optimized_stock(int A[], int n, int S[]) {
//     int *stack = (int *)malloc(n * sizeof(int));
//     int top = -1;

//     S[0] = 1;
//     stack[++top] = 0;

//     for (int i = 1; i < n; i++) {
//         while (top >= 0 && A[stack[top]] <= A[i]) {
//             top--;
//         }
//         S[i] = (top == -1) ? (i + 1) : (i - stack[top]);
//         stack[++top] = i;
//     }

//     free(stack);
// }

void optimized_stock(int A[], int n, int S[]) {
    S[0] = 1;

    for (int i = 1; i < n; i++) {
        int span = 1;
        while ((i - span) >= 0 && A[i] >= A[i - span]) {
            span += S[i - span];
        }
        S[i] = span;
    }
}


void one(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=1;
    }
    return;
}

void input(int arr[],int n){
    printf("enter stock price for %d days\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    return;
}
void display(int arr[],int n){
    printf("The array S[] is\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return;
}

int main(){
    int n;
    printf("enter the number of days: ");
    scanf("%d",&n);

    int A[n],S[n];
    one(S,n);
    input(A,n);

    //brute_stock(A,n,S);
    optimized_stock(A,n,S);
    display(S,n);

}