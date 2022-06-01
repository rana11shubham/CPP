// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
    #define mod 1000000007
  public:
  vector<vector<int>>dp;
  long long int solve(int x,int y,int m,int n){
      // Base case
      if(x==m-1 and y==n-1){
          return 1;
      }
      if(x<0 || x>=m || y<0 || y>=n)
        return 0;
      
      //
      if(dp[x][y]!=0)
        return dp[x][y];
      long long int right_way=solve(x,y+1,m,n);
      long long int down_way=solve(x+1,y,m,n);
      return dp[x][y]=(right_way%mod+down_way%mod)%mod;
  }
    long long int numberOfPaths(int m, int n){
        dp.resize(m,vector<int>(n,0));
        return solve(0,0,m,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends