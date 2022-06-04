// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int nums[], int n)
{        int zero=0,one=0,two=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                zero++;
            else if(nums[i]==1)
                one++;
            else
                two++;
        }
        int idx=0;
        while(zero>0){
            nums[idx]=0;
            zero--;
            idx++;
        }
         while(one>0){
            nums[idx]=1;
            one--;
             idx++;
        }
         while(two>0){
            nums[idx]=2;
            two--;
             idx++;
        }
        
    }
    


// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends