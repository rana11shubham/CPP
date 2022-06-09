class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>&cuts){
        // Base Cases
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int min_ans=1e9;
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts)+solve(k+1,j,cuts);
            min_ans=min(min_ans,cost);
        }
        return dp[i][j]= min_ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        dp.resize(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(1,cuts.size()-2,cuts);
    }
};