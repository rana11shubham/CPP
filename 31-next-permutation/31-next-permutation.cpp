class Solution {
public:
    void reverse1(vector<int>&nums,int i,int j){
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index1=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index1=i;
                break;
            }
        }
        if(index1==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int index2=0;
        for(int i=n-1;i>=0;i--){
            if(nums[index1]<nums[i]){
                index2=i;
                break;
            }
        }
        cout<<index1<<index2<<endl;
        swap(nums[index1],nums[index2]);
        for(auto it:nums)
            cout<<it<<" ";
        reverse1(nums,index1+1,nums.size()-1);
    }
};