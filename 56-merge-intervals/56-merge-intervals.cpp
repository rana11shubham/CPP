class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int>ans=intervals[0];
        vector<vector<int>>final_ans;
        for(auto it:intervals){
            if(it[0]<=ans[1]){
                ans[1]=max(ans[1],it[1]);
            }
            else{
                final_ans.push_back(ans);
                ans=it;
            }
        }
        final_ans.push_back(ans);
        return final_ans;
    }
};