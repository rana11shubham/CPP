class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0,sum1=0;
        for(int i=0;i<n;i++)
        {   sum^=nums[i];
           sum1^=(i+1);
        }
        return sum^sum1;
    }
};