class Solution {
public:
    vector<vector<int>>dp;
    int solve(int m,int n,int col,vector<vector<int>>&triangle){
        // Base cases
          if(m<0 or n<0 or n>col)
            return 1e9+7;
        if(m==0){
            return triangle[m][n];
        }
      
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        int downSum=triangle[m][n]+solve(m-1,n,m-1,triangle);
        int nextdownSum=triangle[m][n]+solve(m-1,n-1,m-1,triangle);
        return dp[m][n]=min(downSum,nextdownSum);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
    int row=triangle.size();
    int col=triangle[row-1].size();
    dp.resize(row,vector<int>(col,-1));
    int ans=INT_MAX;
    for(int i=0;i<col;i++)
    {
        ans=min(ans,solve(row-1,i,row-1,triangle));
    }
        return ans;
    }
};