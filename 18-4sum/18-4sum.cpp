class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<vector<int>>ans;
        if(n<4)
            return ans;
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               int tar=target-(nums[i]+nums[j]);
               int l=j+1;
               int r=n-1;
               while(l<r){
                   if(nums[l]+nums[r]>tar)
                       r--;
                   else if(nums[l]+nums[r]<tar){
                       l++;
                   }
                   else{
                       vector<int>q(4,0);
                       q[0]=nums[i];
                       q[1]=nums[l];
                       q[2]=nums[r];
                       q[3]=nums[j];
                       ans.push_back(q);
                        while(l<r && q[1]==nums[l]){
                            l++;
                        }
                        while(l<r && q[2]==nums[r]){
                            r--;
                        }
                   }
               }
               while(j+1<n and nums[j]==nums[j+1])
                   j++;
           }
           while(i+1<n and nums[i]==nums[i+1])
                   i++;
       }
        return ans;
        
    }
};