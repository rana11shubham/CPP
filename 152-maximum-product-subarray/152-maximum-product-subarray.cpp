class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int l=1,r=1,result=nums[0];
        for(int i=0;i<n;i++){
            l*=nums[i];
            r*=nums[n-i-1];
            result=max(result,max(l,r));
            if(l==0)
                l=1;
            if(r==0)
                r=1;
        }
        return result;
    }
};