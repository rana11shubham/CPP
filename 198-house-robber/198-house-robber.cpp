class Solution {
public:
    int dp[1000];
    int solve(vector<int>&nums,int pos){
        if(pos<0){
            return 0;
        }
        int &ans=dp[pos];
        if(ans!=-1){
            return ans;
        }
        ans=max(solve(nums,pos-1),solve(nums,pos-2)+nums[pos]);
        
        return ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,1000);
        return solve(nums,n-1);
          
        //return op1;
    }
};