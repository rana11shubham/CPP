class Solution {
public:
    vector<int>dp;
    
    bool solve(int i,vector<int>&nums,vector<bool>& vis){
        // Base case
        if(i<0 or i>nums.size()-1)
            return false;
        if(nums[i]==0){
            return true;
        }
        int &ans=dp[i];
        if(ans!=-1)
            return ans;
        int n=nums.size();
        vis[i]=true;
        cout<<i<<" ";
        bool opt1=false;
        bool opt2=false;
           if(i-nums[i]>=0){
                opt1= (!vis[i-nums[i]] and solve(i-nums[i],nums,vis));
           }
          if(i+nums[i]<=n-1){
                opt2= (!vis[i+nums[i]] and solve(i+nums[i],nums,vis));
           }
                  
        return ans= (opt1 || opt2);
    }
    bool canReach(vector<int>& arr, int start) {
        dp.resize(arr.size(),-1);
        vector<bool>vis(arr.size(),false);
        return solve(start,arr,vis);
    }
};