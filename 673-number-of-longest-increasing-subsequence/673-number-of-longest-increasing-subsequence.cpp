class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        vector<int>cnt(n+1,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j] && dp[i]==1+dp[j]){
                    cnt[i]+=cnt[j];
                }
            }
            ans=max(ans,dp[i]);
        }
        int count=0;
        for(int i=0;i<n;i++)
            if(dp[i]==ans)
                count+=cnt[i];
        return count;
    }
};