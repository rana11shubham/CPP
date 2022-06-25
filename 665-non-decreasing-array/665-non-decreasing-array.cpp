class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count=1;
        int ele=INT_MIN;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]<=nums[i]){
                ele=nums[i-1];
            }
            else{
                if(nums[i]<ele){
                    nums[i]=nums[i-1];
                }
                else{
                    nums[i-1]=nums[i];
                }
                count-=1;
            }
        }
          
        return (count>=0);
    }
};