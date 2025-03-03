#include<stdio.h>
#include<math.h>

int is_prime(int num){
    for(int i=2;i<pow(num,0.5);i++){
        if(num%i==0)return 0;
    }
    return 1;
}

void prime(int n){
    int count=0;
    for(int i=2;i<n;i++)
    {
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

    // int num=pow(n,0.5);
    // printf("%d",num);
    prime(n);
    return 0;
}