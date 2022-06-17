class Solution {
public:
    set<vector<int>>ans;
    void solve(vector<int>&nums,int n,int idx,vector<int>&temp){
        // Base cases
        if(idx==n)
        {   sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        if(idx>n)
            return;
        temp.push_back(nums[idx]);
        solve(nums,n,idx+1,temp);
        temp.pop_back();
        solve(nums,n,idx+1,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(nums,n,0,temp);
        vector<vector<int>>result;
        for(auto it:ans)
            result.push_back(it);
        return result;
    }
};