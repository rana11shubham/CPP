class Solution {
public:
    int dp[1001][3];
    int solve(int n,int e){
        // Base cases
        if(e==1 || n==1 || n==0)
            return n;
        if(dp[n][e]!=-1)
            return dp[n][e];
        int ans=INT_MAX;
        for(int k=1;k<=n;k++){
            int pos1=solve(k-1,e-1)+1;
            int pos2=solve(n-k,e)+1;
            ans=min(ans,max(pos1,pos2));
        }
        return dp[n][e]=ans;
    }
    
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,2);    
    }
};