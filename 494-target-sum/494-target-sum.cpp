class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int idx,int target){
        if(idx==(nums.size()-1)){
            if(target==0 && nums[idx]==0)
            return 2;
            if(target==0 || target==nums[idx]){
                return 1;
            }
            return 0;
        }
//         if(target==0){
//             return 1;
//         }
//         if(target<0)
//             return 0;
        
        int opt1=solve(nums,idx+1,target);
        int opt2=0;
        if(target>=nums[idx])
             opt2=solve(nums,idx+1,target-nums[idx]);
        return opt1+opt2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(auto it:nums)
            total+=it;
        if((target+total)%2==1)
            return 0;
        return solve(nums,0,(target+total)/2);
    }
};