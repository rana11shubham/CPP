class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        int len=0;
        for(int j=0;j<n;j++){
            if(nums[j]==1){
                len++;
                ans=max(ans,len);
            }
            else{
               
              len=0;
            }
        }
        return ans;
    }
};