class Solution {
public:
//     vector<vector<int>>dp;
//     int solve(int idx,int prev,vector<int>&nums){
//         // Base Case
//         if(idx==nums.size())
//             return 0;
        
//         if(prev==-1 || nums[idx]%nums[prev]==0 || nums[prev]%nums[idx]==0){
//             return dp[idx][prev+1] =max(1+solve(idx+1,idx,nums),solve(idx+1,prev,nums));
//         }
//         return dp[idx][prev+1]=solve(idx+1,prev,nums);
//     }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        //  solve(0,-1,nums);
        // int max_ele=-1;
        // for(int i=0;i<=nums.size();i++)
        //     for(int j=0;j<=nums.size();j++)
        //         max_ele=max(max_ele,dp[i][j]);
        int n=nums.size();
        vector<pair<int,int>>dp(n+1,{1,-1});
        int max_ele=1;
        int index=0;
        sort(nums.begin(),nums.end());
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                    if(dp[i].first<dp[j].first+1){
                        dp[i]={dp[j].first+1,j};
                    }
                }
            }
            if(max_ele<dp[i].first){
                max_ele=dp[i].first;
                index=i;
            }
        }
        vector<int>ans;
        for(int i=index;i<n;){
            if(dp[i].second==-1){
                ans.push_back(nums[i]);
                break;
            }
            ans.push_back(nums[i]);
            i=dp[i].second;
        }
        return ans;
    }
};