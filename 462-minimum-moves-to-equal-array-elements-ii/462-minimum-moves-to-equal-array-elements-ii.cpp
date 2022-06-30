class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        sort(nums.begin(),nums.end());
        int mid=n/2;
        int target=nums[mid];
        int ans=0;
        for(auto it:nums){
            ans+=abs(it-target);
        }
        return ans;
        
    }
};