class Solution {
public:
    vector<int>dp;
    int solve(int n){
        if(n<=2)
            return n;
        int &ans=dp[n];
        if(ans!=-1)
            return ans;
        return ans=solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};