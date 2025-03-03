// #include<stdio.h>
// #include<stdbool.h>
// #include<math.h>

// int is_prime(int num){
//     for(int i=2;i<pow(num,0.5);i++){
//         if(num%i==0)return 0;
//     }
//     return 1;
// }

// void prime_sive(int m,int n){
//     if(n<=2)return;

//    bool arr[n-m+1];
//    for(int i=0;i<n;i++){
//     arr[i]=true;
//    }

//     int prime=2;
//     while(prime<pow(n,0.5)){
//         if(is_prime(prime)){
//         for(int i=(m/prime)*prime;i<=n-m;i=i+prime){
//             arr[m-i]=false;
//         }
//         }
//         prime++;
//     }

//     for(int i=0;i<=n-m;i++){
//         if(arr[i]){
//             printf("%d ",i+m);
//         }
//     }
// }

// int main(){

//     int m,n;
//     printf("enter m and n: ");
//     scanf("%d%d",&m,&n);
//     prime_sive(m,n);
//     return 0;
// }

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) return 0; 
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void prime_sieve(int m, int n) {
    if (n < 2) return; 


    int size = n - m + 1;
    bool arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = true;
    }

    
    for (int prime = 2; prime <= sqrt(n); prime++) {
        if (is_prime(prime)) {
       
            int start = (m / prime) * prime;
            if (start < m) start += prime;
            if (start == prime) start += prime; 

            
            for (int i = start; i <= n; i += prime) {
                arr[i - m] = false;
            }
        }
    }

  
    for (int i = 0; i < size; i++) {
        if (arr[i] && (i + m) >= 2) { 
            printf("%d ", i + m);
        }
    }
    printf("\n");
}

int main() {
    int m, n;
    printf("Enter m and n: ");
    scanf("%d%d", &m, &n);

    prime_sieve(m, n);

    return 0;
}
