class Solution {
public:
      vector<int>dp;
    int solve(int i,vector<int>&nums){
        // Base case
        if(i>=nums.size()-1){
            return 0;
        }
        int &ans=dp[i];
        if(ans!=-1)
            return ans;
        int n=nums.size();
        int temp=1e9;
        for(int k=i+1;k<=min(n,nums[i]+i);k++){
            temp=min(temp,1+solve(k,nums));
        }
        return ans= temp;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return solve(0,nums);   
    }
};