class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        if(n<=2)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int temp=nums[i];
            cout<<temp<<endl;
            int target=0;
            if(temp!=0)
                target=-temp;
            int j=i+1;
            int e=n-1;
            while(j<e){
                if(nums[j]+nums[e]==target){
                    vector<int>local_ans;
                    local_ans.push_back(temp);
                    local_ans.push_back(nums[j]);
                    local_ans.push_back(nums[e]);
                    ans.push_back(local_ans);
                    int prev_j=nums[j];
                    int prev_e=nums[e];
                    while(j+1<e && nums[j+1]==nums[j]){
                            j++;
                    }
                    while(j<e-1 && nums[e-1]==nums[e]){
                        e--;       
                    }
                    j++;
                    e--;
                }
                else if(nums[j]+nums[e]>target){
                    e--;
                }
                else{
                    j++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
             }
          }   
        return ans;
    }
};