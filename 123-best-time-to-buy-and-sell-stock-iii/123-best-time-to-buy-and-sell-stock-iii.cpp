class Solution {
public:
    int dp[100000][2][3];
    int solve(vector<int>&prices,int pos,int sell,int trans){
        int n=prices.size();
        if(pos>=n || trans==0){
            return 0;
        }
        int &ans=dp[pos][sell][trans];
        if(ans!=-1){
            return ans;
        }
        if(sell==1){
            ans=max(solve(prices,pos+1,1,trans),solve(prices,pos+1,0,trans-1)+prices[pos]);
        }
        else{
             ans=max(solve(prices,pos+1,0,trans),solve(prices,pos+1,1,trans)-prices[pos]);
        }
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0,2);
    }
};
