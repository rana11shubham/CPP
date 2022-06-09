class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int max_ans=INT_MIN;
        for(int k=i;k<=j;k++){
            int ans=nums[i-1]*nums[k]*nums[j+1]+solve(nums,i,k-1)+solve(nums,k+1,j);
            max_ans=max(ans,max_ans);
        }
        return dp[i][j]= max_ans;
    }
    
    int maxCoins(vector<int>& nums) {
       
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(nums,1,nums.size()-2);
    }
};