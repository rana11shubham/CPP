class Solution {
public:
    
    int solve(int x,int y,int n,int m,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        
        if(x>=n or y>=m)
            return 0;
        if(obstacleGrid[x][y]==1){
            return 0;
        }
        if(x==n-1 and y==m-1)
            return 1;
        if(dp[x][y]!=-1)
            return dp[x][y];
        int rightWays=solve(x,y+1,n,m,obstacleGrid,dp);
        int downWays=solve(x+1,y,n,m,obstacleGrid,dp);
        return dp[x][y]= (rightWays + downWays);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,obstacleGrid,dp);
    }
};