class Solution {
public:
    int dp[5001][2];
    int solve(int i,int buy,vector<int>&prices){
        // Base case
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int ans=0;
        if(buy==1){
            ans=max(solve(i+1,buy,prices),solve(i+1,1-buy,prices)-prices[i]);
        }
        else{
            ans=max(solve(i+1,buy,prices),solve(i+2,1-buy,prices)+prices[i]);
        }
        return dp[i][buy]= ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,prices);
    }
};