class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=1;
        for(int i=0,j=1;j<n;j++){
            if(nums[i]==nums[j]){
                continue;
            }
            else{
                k++;
                nums[++i]=nums[j];
            }
        }
        return k;
    }
};