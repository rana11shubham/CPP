class Solution {
public:
    int bs(vector<int>&nums,int start,int end,int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0,end=n-1,min_loc=-1;
        while(start<=end){
            if(nums[start]<=nums[end]){
                min_loc=start;
                if(target==nums[min_loc])
                    return min_loc;
                break;
            }
            int mid=start+(end-start)/2;
            cout<<mid;
            if(nums[mid]<nums[((mid-1)+n)%n] && nums[mid]<nums[(mid+1)==n?0:mid+1]){
                min_loc=mid;
                cout<<min_loc;
                if(target==nums[mid])
                    return mid;
                break;
            }
            else if(nums[mid]<nums[start]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
       int opt1=bs(nums,0,min_loc-1,target);
       int opt2=bs(nums,min_loc+1,n-1,target);
        cout<<min_loc;
        return (opt1==-1)?opt2:opt1;
    }
};