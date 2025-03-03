/*Que:1 you are given an empty board with k consecutive cells,at any moment each cell can display one character you want the board to display a string 
s with lenght n >k, since board is not larg enough have to display string in n-k+1 steps
calculate power rwequired to display the whole string
power required=no.of differing characters in two consecutive display
*/

#include<stdio.h>
#include<string.h>

int Brute_power_consumed(char str[],int n,int k){
        int power=0;
        int m=0;

        while(m<n-k){  // --->O(n-k)
            int i=m;
            int j=m+k;

            for(int p=0;p<k;p++){  // --->O(k)
                if(str[i]!=str[j]){
                power++;
            }
            i++,j++;
            }
            
            m++;
        }
        return power;   //-->O((n-k)*k)
}

// int Optimized_power_consumed(char str[], int n, int k) {
//     int power = 0;

//     // Compute power for the first window (not counted in total)
//     for (int i = 0; i < k - 1; i++) {
//         if (str[i] != str[i + 1]) {
//             power++;
//         }
//     }

//     int total_power = 0;

//     // Slide the window across the string
//     for (int m = 1; m <= n - k; m++) {
//         total_power += power; // Add current power count

//         // Update power by checking only the first outgoing and last incoming characters
//         if (str[m - 1] != str[m]) {
//             power--;  // Character leaving the window
//         }
//         if (str[m + k - 2] != str[m + k - 1]) {
//             power++;  // New character entering the window
//         }
//     }

//     return total_power;
// }

int optimized_power_consumed(char str[], int k) {
    int n = strlen(str);
    int power = 0, totalPower = 0;

    for (int i = 1; i <= k; i++) {
        if (str[i] != str[i - 1]) {
            power++;
        }
    }
    
    totalPower = power;

    for (int i = 2; i <= n - k; i++) {
        if (str[i-1] != str[i - 2]) {
            power--;
        }
        if (str[i + k - 1] != str[i + k - 2]) {
            power++;
        }
        totalPower += power;
    }

    return totalPower;
}



int main(){
    char str[20];
    int k;~
    printf("enter the string to display: ");
    gets(str);
    printf("enter k: ");
    scanf("%d",&k);
    int n=strlen(str);
    //int power=Brute_power_consumed(str,n,k);  
    
    int power=Brute_power_consumed(str,n,k);
    printf("power consumed: %d\n",power);

}