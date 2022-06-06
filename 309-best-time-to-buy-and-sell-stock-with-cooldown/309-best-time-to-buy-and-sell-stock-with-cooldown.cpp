class Solution {
public:
    // buy=0 means I want to sell the stock
    // buy=1 means I want to buy the stock
    vector<vector<int>>dp;
    int solve(vector<int>&prices,int idx,int buy,int n){
        // Base Cases
        if(idx>=n)
            return 0;
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        if(buy==1){
            return dp[idx][buy]=max(solve(prices,idx+1,buy,n),solve(prices,idx+1,0,n)-prices[idx]);
        }
        
            return dp[idx][buy]=max(solve(prices,idx+1,buy,n),solve(prices,idx+2,1,n)+prices[idx]);
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return solve(prices,0,1,n);
    }
};