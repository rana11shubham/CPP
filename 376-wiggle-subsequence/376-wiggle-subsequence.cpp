class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>diff;
        int ans=0;
        for(int i=1;i<n;i++){
            diff.push_back(nums[i]-nums[i-1]);
        }
        int flag=0;
        for(auto it:diff){
            if(it!=0)
                flag=1;
        }
        if(flag==0)
            return 1;
        vector<int>dp(n-1,1);
        int count=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n-1;j++){
                if(diff[i]>0){
                    if(diff[j]<0){
                        dp[i]=max(dp[i],1+dp[j]);
                    }
                }
                else if(diff[i]==0)
                    continue;
                else{
                    if(diff[j]>0){
                        dp[i]=max(dp[i],1+dp[j]);
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans+1;
    }
};