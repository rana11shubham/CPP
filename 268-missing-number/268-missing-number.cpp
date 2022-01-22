class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
        {
           // big=max(big,it);
            sum+=it;
        }
        int ans=(n*(n+1))/2-sum;
        return ans;
    }
};