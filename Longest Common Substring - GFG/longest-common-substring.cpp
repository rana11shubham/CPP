// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // int ans=0;
    // int dp[1001][1001];
    // int solve(int x,int y,string S1,string S2){
    //     if(x<0 || y<0)
    //         return 0;
    //     if(dp[x][y]!=-1){
    //         ans=max(ans,dp[x][y]);
    //         return dp[x][y];
    //     }
    //     solve(x-1,y,S1,S2);
    //     solve(x,y-1,S1,S2);
    //     if(S1[x]==S2[y]){
    //          dp[x][y]= 1+solve(x-1,y-1,S1,S2);
    //          ans=max(ans,dp[x][y]);
    //          return dp[x][y];
    //     }
        
    //     return dp[x][y]= 0;
    // }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {   int dp[n+1][m+1]={0};
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends