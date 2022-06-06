// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dp[501][2][201];
    int solve(int prices[],int idx,int buy,int trans,int N){
        // Base cases
        if(trans==0)
            return 0;
        if(idx==N)
            return 0;
        if(dp[idx][buy][trans]!=-1)
            return dp[idx][buy][trans];
        if(buy==1){
            return dp[idx][buy][trans]= max(solve(prices,idx+1,buy,trans,N),solve(prices,idx+1,1-buy,trans,N)-prices[idx]);
        }
        else{
            return dp[idx][buy][trans]= max(solve(prices,idx+1,buy,trans,N),solve(prices,idx+1,1-buy,trans-1,N)+prices[idx]);
        }
    }
    
    int maxProfit(int K, int N, int A[]) {
        memset(dp,-1,sizeof(dp));
        return solve(A,0,1,K,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends