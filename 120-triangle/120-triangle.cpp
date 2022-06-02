class Solution {
public:
    vector<vector<int>>dp;
    int solve(int m,int n,int row,int col,vector<vector<int>>&triangle){
        // Base cases
          if(m>row or n>col)
            return 1e9+7;
        if(m==row){
            return triangle[m][n];
        }
      
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int downSum=triangle[m][n]+solve(m+1,n,row,col,triangle);
        int nextdownSum=triangle[m][n]+solve(m+1,n+1,row,col,triangle);
        return dp[m][n]=min(downSum,nextdownSum);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
    int row=triangle.size();
    int col=triangle[row-1].size();
    dp.resize(row,vector<int>(col,-1));
    int ans=INT_MAX;
        return solve(0,0,row-1,col-1,triangle);
    
        return ans;
    }
};