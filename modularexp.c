#include<stdio.h>

typedef struct triplet{
    int x;
    int y;
    int gcd;
}triplet;

int modularexp(int x,int y,int p){ // find (x^y)%p

    //(x*y)%p=(X%p * y*p)%p

    if(x<p){

        int res=1;
        for(int i=0;i<y;i++){
            res=(res*x)%p;
        }
        return res;
    }

    else{
        int res=1;
        x=x%p;
        while(y>0){
            if(y%2==1){
                res=(res*x)%p;
            }
            y=y/2;
            x=(x*x)%p;
        }
        return res;
    }

}




int main(){

int x,y,p;
printf("Enter a,m and p: ");
scanf("%d %d %d",&x,&y,&p);
int ans=modularexp(x,y,p);
printf("ans: %d ",ans);
return 0;
}