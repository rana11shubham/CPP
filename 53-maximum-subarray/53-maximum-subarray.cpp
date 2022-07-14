class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum=0,max_sum=INT_MIN;
        for(auto it:nums){
            cur_sum=max(cur_sum+it,it);
            max_sum=max(max_sum,cur_sum);
        }
        return max_sum;
    }
};