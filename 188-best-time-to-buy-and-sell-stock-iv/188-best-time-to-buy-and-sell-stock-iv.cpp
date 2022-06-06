class Solution {
public:
    int dp[1001][2][101];
    int solve(vector<int>&prices,int idx,int buy,int trans,int N){
        // Base cases
        if(trans==0)
            return 0;
        if(idx==N)
            return 0;
        if(dp[idx][buy][trans]!=-1)
            return dp[idx][buy][trans];
        if(buy==1){
            return dp[idx][buy][trans]= max(solve(prices,idx+1,buy,trans,N),solve(prices,idx+1,1-buy,trans,N)-prices[idx]);
        }
        else{
            return dp[idx][buy][trans]= max(solve(prices,idx+1,buy,trans,N),solve(prices,idx+1,1-buy,trans-1,N)+prices[idx]);
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1,k,n);
    }
};