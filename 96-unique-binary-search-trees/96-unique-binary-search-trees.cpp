class Solution {
public:
    int dp[20];
    int solve(int n){
        if(n==0)
            return 1;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int ans=0;
        if(dp[n]!=-1)
            return dp[n];
        for(int i=1;i<=n;i++){
            ans+=(solve(i-1)*solve(n-i));
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        if(n==0)
            return 0;
        dp[0]=1;
        return solve(n);
    }
};