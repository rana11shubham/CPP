class Solution {
public:
   
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0,sum1=0;
        int ans=INT_MIN;
        unordered_map<int,int>mp;
        for(auto it:nums)
            sum+=it;
        if(sum==x)
            return nums.size();
        int target=sum-x;
        for(int i=0;i<n;i++){
            sum1+=nums[i];
            if(sum1==target){
                ans=max(ans,i+1);
            }
            else if(mp.find(sum1-target)!=mp.end())
                ans=max(ans,i-mp[sum1-target]);
            mp[sum1]=i;
        }
        return ans==INT_MIN?-1:n-ans;
    }
};