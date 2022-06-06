class Solution {
public:
    vector<int>P;
    vector<vector<int>>dp;
    int solve(int idx,int buy){
        // Base Cases
        if(idx>=P.size())
            return 0;
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        if(buy==1){
            int opt1=solve(idx+1,1-buy)-P[idx];
            int opt2=solve(idx+1,buy);
            return dp[idx][buy]= max(opt1,opt2);
        }
        int opt1=solve(idx+1,1-buy)+P[idx];
        int opt2=solve(idx+1,buy);
        return dp[idx][buy]= max(opt1,opt2);
        
        }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        P=prices;
        dp.resize(n+1,vector<int>(2,-1));
        return solve(0,1);
    }
};