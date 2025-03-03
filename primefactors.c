#include<stdio.h>
#include<stdbool.h>
#include<math.h>

void prime_factors(int n){
    
    int prime[n+1];
    for(int i=0;i<=n;i++){
        prime[i]=i;
    }

    for(int p=2;p*p<=n;p++){
        if(prime[p]==p){ // p is prime
            for(int i=p*p;i<=n;i+=p){
                if(prime[i]==i){
                    prime[i]=p; //marking smallest prime factor of i as p
                }
            }

        }
    }

    while(n>1){
        printf("%d ",prime[n]);
        n=n/prime[n];
    }
    printf("\n");
return;
}

int main(){

    int n;
    printf("enter n: ");
    scanf("%d",&n);

    prime_factors(n);
    return 0;
}