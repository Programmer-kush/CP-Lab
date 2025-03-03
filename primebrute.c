#include<stdio.h>

int is_prime(int num){
    for(int i=2;i<num/2;i++){
        if(num%i==0)return 0;
    }
    return 1;
}

void prime(int n){

    int count=0;
    for(int i=2;i<n;i++){
        if(is_prime(i)){
            printf("%d ",i);
            ++count;
        }
    }
        printf("\nThere are %d prime numbers upto %d",count,n);
}

int main(){

    int n;
    printf("enter n: ");
    scanf("%d",&n);

    prime(n);
    return 0;
}