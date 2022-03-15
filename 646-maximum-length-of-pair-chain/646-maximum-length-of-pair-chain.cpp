class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int>dp(n,0);
        sort(pairs.begin(),pairs.end());
        dp[n-1]=1;
        int ans=1;
        for(int i=n-2;i>=0;i--){
            int b=pairs[i][1];
           for(int j=i+1;j<n;j++){
               int c=pairs[j][0];
               if(b<c){
                   dp[i]=max(dp[i],1+dp[j]);
                   ans=max(ans,dp[i]);
               }
           }
        }
        return ans;
    }
};