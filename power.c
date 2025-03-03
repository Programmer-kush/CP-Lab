#include<stdio.h>

int power(int x,int n){
if(n==1)return x;


//return x*power(x,n-1); -->O(n)

int result=power(x,n/2);

if(n%2==0) return result*result; // -->O(logn)
else return result*result*x;  
}

int power2(int x,int n){

int ans=x;
int i;

for(i=1;i<n;i++){  // -->O(n)
ans=x*ans;
}

return ans;

}

double iterative(double x,int n){
if(n==0)return 1;
int exp=n;
double ans=1;
if(n<0){
    x=1/x;
    exp=-n;
}
while(exp>0){
    if(exp%2==1){
        ans*=x;
    }
    x*=x;
    exp/=2;
}
return ans;
}


int main(){
int x,n;
printf("enter x and n: ");
scanf("%d",&x);
scanf("%d",&n);

double ans=iterative(x,n);
printf("value of %d raise to power %d: %lf",x,n,ans);

}

