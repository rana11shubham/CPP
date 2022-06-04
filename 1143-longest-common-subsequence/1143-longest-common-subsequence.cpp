class Solution {
public:
    vector<vector<int>>dp;
    int solve(string& S1,string& S2,int idx1,int idx2,int n,int m){
        // Base cases
        if(idx1<0 or idx2<0)
            return 0;
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        if(S1[idx1]==S2[idx2])
            return dp[idx1][idx2]=1+solve(S1,S2,idx1-1,idx2-1,n,m);
        return dp[idx1][idx2]=max(solve(S1,S2,idx1-1,idx2,n,m),solve(S1,S2,idx1,idx2-1,n,m));
    }
       // int dp[1000 + 1][1000 + 1];
    
//     int maxLen(string& s1, string& s2, int n, int m)
//     {
//         if (n == 0 || m == 0)
//             return 0;
        
//         if (dp[n][m] != -1)
//             return dp[n][m];

//         if (s1[n - 1] == s2[m - 1])
//             return dp[n][m] = 1 + maxLen(s1, s2, n - 1, m - 1);
//         else
//             return dp[n][m] = max(0 + maxLen(s1, s2, n - 0, m - 1), 0 + maxLen(s1, s2, n - 1, m - 0));
//     }
    int longestCommonSubsequence(string S1, string S2) {
        int n=S1.length();
        int m=S2.length();
       dp.assign(n+1,vector<int>(m+1,-1));
     //  memset(dp,-1,sizeof(dp));
        return solve(S1,S2,n-1,m-1,n,m);         
    }
};