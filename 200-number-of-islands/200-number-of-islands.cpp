class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        auto it=q.front();
                        q.pop();
                        int r=it.first;
                        int c=it.second;
                        if(r-1>=0 && grid[r-1][c]=='1')
                        {
                            grid[r-1][c]='0';
                            q.push({r-1,c});
                        }
                        
                        if(c-1>=0 && grid[r][c-1]=='1')
                        {
                            grid[r][c-1]='0';
                            q.push({r,c-1});
                        }
                        
                        if(r+1<=n-1 && grid[r+1][c]=='1')
                        {
                            grid[r+1][c]='0';
                            q.push({r+1,c});
                        }
                        
                        if(c+1<=m-1 && grid[r][c+1]=='1')
                        {
                            grid[r][c+1]='0';
                            q.push({r,c+1});
                        }
                    }
                }
            }
        }
        return count;
    }
};