class Solution {
public:
    #define inf 1e+7
    int dp[1001][1001];
    bool vis[1001][1001];
    int solve(int i,int j,int n){
        // Base case
        if(i>n){
            return inf;
        }
        if(i==n)
            return 0;
        if(vis[i][j]==true){
            return inf;
        }
        vis[i][j]=true;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //copy
        int opt1= 1+solve(i,i,n);
        //paste
        int opt2=1+solve(i+j,j,n);
        return dp[i][j]= min(opt1,opt2);
    }
    int minSteps(int n) {
      memset(dp,-1,sizeof(dp));
      memset(vis,false,sizeof(vis));
      return solve(1,0,n);
        
    }
};