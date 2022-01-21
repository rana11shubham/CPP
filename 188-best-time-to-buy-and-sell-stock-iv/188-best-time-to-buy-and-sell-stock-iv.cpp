class Solution {
public:
    int dp[1001][2][101];
    int solve(vector<int>&prices,int pos,int sell,int k){
        int n=prices.size();
        if(pos>=n || k==0){
            return 0;
        }
        int &ans=dp[pos][sell][k];
        if(ans!=-1){
            return ans;
        }
        if(sell==1){
            ans=max(solve(prices,pos+1,sell,k),solve(prices,pos+1,1-sell,k-1)+prices[pos]);
        }
        else{
            ans=max(solve(prices,pos+1,sell,k),solve(prices,pos+1,1-sell,k)-prices[pos]);
        }
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0,k);
    }
};