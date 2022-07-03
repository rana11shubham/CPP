// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans=new int[2];
        int xor_arr=0;
        for(int i=0;i<n;i++)
            xor_arr^=arr[i];
        int xor_full=0;
        for(int i=1;i<=n;i++)
            xor_full^=i;
        int temp=xor_full^xor_arr;
        int set_bit=temp&(~(temp-1));
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            if((i&set_bit)!=0)
                a^=i;
            else b^=i;
        }
        for(int i=0;i<n;i++){
            if((arr[i]&set_bit)!=0)
                a^=arr[i];
            else b^=arr[i];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==a)
                count=1;
        }
        if(count==1){
            ans[0]=a;
            ans[1]=b;
        }
        else{
            ans[0]=b;
            ans[1]=a;
        }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends