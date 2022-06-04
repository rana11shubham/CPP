class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        for(auto it:nums){
            if(it==0)
                zero++;
            else if(it==1)
                one++;
            else
                two++;
        }
        int idx=0;
        while(zero>0){
            nums[idx]=0;
            zero--;
            idx++;
        }
         while(one>0){
            nums[idx]=1;
            one--;
             idx++;
        }
         while(two>0){
            nums[idx]=2;
            two--;
             idx++;
        }
        
    }
};