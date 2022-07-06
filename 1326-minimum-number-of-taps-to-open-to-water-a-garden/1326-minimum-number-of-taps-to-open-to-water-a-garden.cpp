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
    int minTaps(int n, vector<int>& ranges) {
        dp.resize(n+1,-1);
        vector<int>ans(n+1,0);
        for(int i=0;i<ranges.size();i++){
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            ans[l]=max(ans[l],r-l);
        }
        for(auto it:ans)
            cout<<it<<" ";
        int res = solve(0,ans);
        return (res==1e9)?-1:res;
    }
};