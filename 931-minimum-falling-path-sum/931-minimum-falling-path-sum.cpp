class Solution {
public:
    vector<vector<int>>dp;
    int solve(int x,int y,int row,int col,vector<vector<int>>&matrix){
        // Base cases
         if(x>=row || y<0  || y>=col)
            return 1e9+7;
        if(x== row-1)
            return matrix[x][y];
       
        if(dp[x][y]!=-1)
            return dp[x][y];
        int downSum=solve(x+1,y,row,col,matrix)+matrix[x][y];
        int leftdownSum=solve(x+1,y-1,row,col,matrix)+matrix[x][y];
        int rightdownSum=solve(x+1,y+1,row,col,matrix)+matrix[x][y];
        return dp[x][y]= min(downSum,min(leftdownSum,rightdownSum));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        dp.resize(row,vector<int>(col,-1));
        int ans=1e9+7;
        for(int i=0;i<col;i++){
            ans=min(ans,solve(0,i,row,col,matrix));
        }
        return ans;
    }
};