// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        // Code here
        int ansF=-1,ansL=-1;
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]==x){
                ansF=mid;
                j=mid-1;
            }
            else if(arr[mid]>x)
                j=mid-1;
            else i=mid+1;
        }
        i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]==x){
                ansL=mid;
                i=mid+1;
            }
            else if(arr[mid]>x)
                j=mid-1;
            else i=mid+1;
        }
        if(ansF==-1 && ansL==-1)
            return {-1};
       return{ansF,ansL};
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends