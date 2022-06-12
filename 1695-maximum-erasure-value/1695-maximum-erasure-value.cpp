class Solution {
public:
    unordered_map<int,int>mp;
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int ans=0;
        int sum=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(nums[i])!=mp.end()){
               int idx=mp[nums[i]];
                while(j<=idx){
                    sum-=nums[j];
                    j++;
                }
            }
            mp[nums[i]]=i;
            ans=max(ans,sum);
        }
        
        return ans;
    }
};