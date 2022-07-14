class Solution {
public:
   
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum-x;
        if(target<0)
            return -1;
        if(target==0)
            return n;
        int i=0,j=0,sum1=0,ans=-1;
        while(j<n){
            sum1+=nums[j];
            if(sum1==target){
               ans=max(ans,j-i+1);
                sum1-=nums[i];
                i++;
                j++;
            }
            else if(sum1>target){
                sum1-=nums[i];
                sum1-=nums[j];
                i++;
            }
            else{
                j++;
            }
        }
        return ans==-1?-1:n-ans;
    }
};