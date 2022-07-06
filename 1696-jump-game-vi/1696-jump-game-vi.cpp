class Solution {
public:
   
    int maxResult(vector<int>& nums, int k) {
       multiset<int>mp;
       int n=nums.size();
       vector<int>dp(n,0);
        dp[0]=nums[0];
        mp.insert(dp[0]);
       for(int i=1;i<n;i++){
           if(i>k){
               mp.erase(mp.find(dp[i-k-1]));
           }
           mp.insert(dp[i]=*rbegin(mp)+nums[i]);
       }
        return dp[n-1];
    }
};