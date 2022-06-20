class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>mp(nums.begin(),nums.begin()+k);
        for(int i=k;i<nums.size();i++){
            if(mp.top()<nums[i]){
                mp.pop();
                mp.push(nums[i]);
            }
        }
         return mp.top();
    }
};