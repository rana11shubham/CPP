// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    vector<vector<int>>dp;
    int solve(int price[],int idx,int W,int n){
        if(idx>n)
            return 0;
        if(W==0){
            return 0;
        }
        if(W<0){
            return -1e9;
        }
        int &ans=dp[idx][W];
        if(ans!=-1)
            return ans;
        int opt1=solve(price,idx+1, W, n);
        int opt2=solve(price,idx,W-idx,n)+price[idx-1];
        return ans= max(opt1,opt2);
    }
    int cutRod(int price[], int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(price,1,n,n);
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
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends