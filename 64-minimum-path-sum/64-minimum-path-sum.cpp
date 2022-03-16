class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int cost[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0){
                    if(j==0){
                        cost[i][j]=grid[i][j];
                    }
                    else{
                        cost[i][j]=cost[i][j-1]+grid[i][j];
                    }
                }
                else if(j==0){
                        cost[i][j]=cost[i-1][j]+grid[i][j];
                }
                else{
                        cost[i][j]=min(cost[i][j-1]+grid[i][j],cost[i-1][j]+grid[i][j]);
                }
            }
        }
        return cost[row-1][col-1];
    }
};