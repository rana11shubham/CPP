class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&prices,int idx,int buy,int fee){
        // Base Cases
        if(idx==prices.size())
            return 0;
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        if(buy==1){
            int opt1=solve(prices,idx+1,buy,fee);
            int opt2=solve(prices,idx+1,0,fee)-prices[idx];
            return dp[idx][buy]= max(opt1,opt2);
        }
        int opt1=solve(prices,idx+1,buy,fee);
        int opt2=solve(prices,idx+1,1,fee)+prices[idx]-fee;
        return dp[idx][buy]= max(opt1,opt2);
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return solve(prices,0,1,fee);
    }
};