class Solution {
public:
    int ans;
    bool isValid(vector<vector<char>> &grid,int row,int col,int n){
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(grid[i][j]=='Q')
                return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(grid[i][j]=='Q')
                return false;
        }
        return true;
        
    }
    void solve(vector<vector<char>> &grid,int row,int n){
        // Base case
        if(row==n){
            ans++;
            return;
        }
        for(int i=0;i<=n-1;i++){
            if(isValid(grid,row,i,n)){
                grid[row][i]='Q';
                solve(grid,row+1,n);
                grid[row][i]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<char>>grid(n,vector<char>(n,'.'));
        solve(grid,0,n);
        return ans;
    }
};