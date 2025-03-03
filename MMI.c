#include<stdio.h>

typedef struct triplet{
    int x;
    int y;
    int gcd;
}triplet;

triplet extended_euclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallans=extended_euclid(b,a%b);
    triplet ans;
    ans.x=smallans.y;
    ans.y=smallans.x-(a/b)*smallans.y;
    ans.gcd=smallans.gcd;
    return ans;
}

int main(){

int a,b;
printf("Enter a and m: ");
scanf("%d %d",&a,&b);
triplet ans=extended_euclid(a,b);
printf("MMI: %d ",(ans.x+b)%b);
return 0;
}