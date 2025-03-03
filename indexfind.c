#include<stdio.h>

int binarysearch(int arr[],int low,int high,int x){
    int mid=(high+low)/2;

    if(arr[mid]==x) return mid;

    else if(x>arr[mid]){
        return binarysearch(arr,mid+1,high,x);
    }
    else if(x<arr[mid]){
        return binarysearch(arr,low,mid-1,x);
    }   
}
int findpivot(int arr[],int low,int high){
    if(arr[low]>arr[high] && high-low==1) return high;

    int mid=(low+high)/2;
    if(arr[mid]>arr[low]){
        return findpivot(arr,mid,high);
    }
    else if(arr[mid]<arr[low]){
        return findpivot(arr,low,mid);
    }
   
}

int findElement(int arr[], int low, int high, int x) {
    if (low > high) return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == x) return mid;

    if (arr[low] <= arr[mid]) {
        if (x >= arr[low] && x <= arr[mid]) {
            return findElement(arr, low, mid - 1, x);
        }
        return findElement(arr, mid + 1, high, x);
    }

    if (x >= arr[mid] && x <= arr[high]) {
        return findElement(arr, mid + 1, high, x);
    }

    return findElement(arr, low, mid - 1, x);
}

int brute_search(int arr[],int n,int e){
    for(int i=0;i<n;i++){
        if(arr[i]==e) return i;
    }
}

int main(){
    int arr[]={4,5,6,7,1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int element;
    printf("enter element to search: ");
    scanf("%d",&element);

    int pivot_index=findpivot(arr,0,n-1);
    //printf("pivot is %d\nindex: %d",arr[pivot_index],pivot_index);

        int index;
        if(element>arr[0]){
            index=binarysearch(arr,0,pivot_index,element);
        }
        else if(arr[0]==element) index=0;
        else index=binarysearch(arr,pivot_index,n-1,element);

        printf("\nindex is %d",index);
      
}