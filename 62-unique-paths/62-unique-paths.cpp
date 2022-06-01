class Solution {
public:
    vector<vector<int>>dp;
    int solve(int x,int y,int m,int n){
      // Base case
      if(x==m-1 and y==n-1){
          return 1;
      }
      if(x<0 || x>=m || y<0 || y>=n)
        return 0;
      
      //
      if(dp[x][y]!=0)
        return dp[x][y];
       int right_way=solve(x,y+1,m,n);
       int down_way=solve(x+1,y,m,n);
      return dp[x][y]=(right_way+down_way);
  }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,0));
        return solve(0,0,m,n);
    }
};