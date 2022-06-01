class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto &it:nums){
            sum+=it;
            it=sum;
        }
        return nums;
    }
};