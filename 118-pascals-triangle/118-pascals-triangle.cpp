class Solution {
public:
    vector<vector<int>>final_ans;
    vector<int> solve(int n){
        if(n==1)
            return {1};
        if(n==2)
            return {1,1};
        vector<int>prev_Pascal=solve(n-1);
        vector<int>ans;
        ans.push_back(1);
        for(int i=0;i<prev_Pascal.size()-1;i++){
            ans.push_back((prev_Pascal[i]+prev_Pascal[i+1]));
        }
        ans.push_back(1);
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        for(int i=1;i<=numRows;i++)
        final_ans.push_back(solve(i));
        return final_ans;
    }
};