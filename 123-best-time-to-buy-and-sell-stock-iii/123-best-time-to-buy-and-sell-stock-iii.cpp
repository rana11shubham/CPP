class Solution {
public:
    int dp[100001][2][3];
    int solve(vector<int>&prices,int idx,int buy,int trans){
        // Base cases
        if(trans==0)
            return 0;
        if(idx==prices.size())
            return 0;
        if(dp[idx][buy][trans]!=-1)
            return dp[idx][buy][trans];
        if(buy==1){
            return dp[idx][buy][trans]= max(solve(prices,idx+1,buy,trans),solve(prices,idx+1,1-buy,trans)-prices[idx]);
        }
        else{
            return dp[idx][buy][trans]= max(solve(prices,idx+1,buy,trans),solve(prices,idx+1,1-buy,trans-1)+prices[idx]);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1,2);
    }
};