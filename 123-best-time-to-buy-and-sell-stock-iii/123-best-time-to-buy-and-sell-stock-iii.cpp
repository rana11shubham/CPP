class Solution {
public:
    int dp[100001][2][2];
    int solve(int i,int buy,int trans,vector<int>&prices){
        // Base case
        if(i==prices.size()){
            return 0;
        }
        if(trans<0){
            return 0;
        }
        if(dp[i][buy][trans]!=-1)
            return dp[i][buy][trans];
        int ans=0;
        if(buy==1){
            ans=max(solve(i+1,buy,trans,prices),solve(i+1,1-buy,trans,prices)-prices[i]);
        }
        else{
            ans=max(solve(i+1,buy,trans,prices),solve(i+1,1-buy,trans-1,prices)+prices[i]);
        }
        return dp[i][buy][trans]= ans;
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       memset(dp,-1,sizeof(dp));
        return solve(0,1,1,prices);
    }
};