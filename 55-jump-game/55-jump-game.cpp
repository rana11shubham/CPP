class Solution {
public:
    vector<int>dp;
    bool solve(int i,vector<int>&nums){
        // Base case
        if(i>=nums.size()-1){
            return true;
        }
        int &ans=dp[i];
        if(ans!=-1)
            return ans;
        int n=nums.size();
        for(int k=i+1;k<=min(n,nums[i]+i);k++){
            if(solve(k,nums)){
             return ans= true;
            }
        }
        return ans= false;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return solve(0,nums);
    }
};