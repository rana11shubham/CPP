class Solution {
public:
    vector<vector<int>>dp;
    int solve(int x,int y,int n,int m,vector<vector<int>>&grid){
        
        if(x==n-1 and y==m-1)
            return grid[x][y];
        if(x<0 or y<0 or x>n-1 or y>m-1)
            return 1e9+7;
        if(dp[x][y]!=-1)
            return dp[x][y];
        
        int rightSum=grid[x][y]+solve(x,y+1,n,m,grid);
        int bottomSum=grid[x][y]+solve(x+1,y,n,m,grid);
        return dp[x][y]=min(rightSum,bottomSum);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,n,m,grid);
    }
};