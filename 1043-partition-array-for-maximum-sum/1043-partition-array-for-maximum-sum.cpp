class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&arr,int k,int i){
        // Base Case
        int n=arr.size();
        
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int max_ele=INT_MIN;
        int ans=INT_MIN;
        int len=0;
        for(int m=i;m<min(i+k,n);m++){
            len++;
            max_ele=max(arr[m],max_ele);
            int temp=(len)*max_ele+solve(arr,k,m+1);
            ans=max(ans,temp);
        }
        return dp[i]= ans;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        return solve(arr,k,0);
    }
};