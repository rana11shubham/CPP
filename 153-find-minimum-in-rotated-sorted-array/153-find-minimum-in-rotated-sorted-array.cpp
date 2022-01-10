class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1;
        if(nums[0]<=nums[n-1])
            return nums[0];
        while(start<=end){
            if(nums[start]<nums[end])
                return nums[start];
            int mid=start+(end-start)/2;
            if(nums[mid]<nums[(mid+1)%n] && nums[mid]<nums[(mid+n-1)%n]){
                return nums[mid];
            }
            else if(nums[mid]<nums[start]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return 0;
    }
};