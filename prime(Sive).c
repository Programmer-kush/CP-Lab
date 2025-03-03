#include<stdio.h>
#include<stdbool.h>
#include<math.h>
void prime_sive(int n){
    if(n<=2)return;

   bool arr[n+1];
   for(int i=0;i<n;i++){
    arr[i]=true;
   }

    int prime=2;
    while(prime<pow(n,0.5)){
        if(arr[prime]){
        for(int i=prime*prime;i<=n;i=i+prime){
            arr[i]=false;
        }
        }
        prime++;
    }

    for(int i=2;i<=n;i++){
        if(arr[i]){
            printf("%d ",i);
        }
    }
}

int main(){

    int n;
    printf("enter n: ");
    scanf("%d",&n);
    prime_sive(n);
    return 0;
}