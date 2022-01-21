class Solution {
public:
    int dp[101];
    // int solve(vector<int>&nums,int pos){
    //     int n=nums.size();
    //     if(pos>=n){
    //         return 0;
    //     }
    //     int &ans=dp[pos];
    //     if(ans!=-1){
    //         return ans;
    //     }
    //     ans=max(solve(nums,pos+1),solve(nums,pos+2)+nums[pos]);
    //     return ans;
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,0,101);
        // int op1= solve(nums,0);
        // int ans=0;
        // for(int i=0;i<n;i++)
        //     ans=max(ans,dp[i]);
        dp[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--){
           if(n==2)
               dp[i]=max(nums[i],nums[i+1]);
           else
           {
               dp[i]=max(dp[i+2]+nums[i],dp[i+1]);
           }
       }
        return max(dp[0],dp[1]);
        //return ans;
    }
};