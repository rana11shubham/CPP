class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        auto it=q.front();
                        q.pop();
                        int r=it.first;
                        int c=it.second;
                        if(r-1<0 || grid[r-1][c]==0)
                            count++;
                        if(r-1>=0 && !vis[r-1][c] && grid[r-1][c])
                        {
                            vis[r-1][c]=1;
                            q.push({r-1,c});
                        }
                        if(c-1<0 || grid[r][c-1]==0)
                            count++;
                        if(c-1>=0 && !vis[r][c-1] && grid[r][c-1])
                        {
                            vis[r][c-1]=1;
                            q.push({r,c-1});
                        }
                        if(r+1>n-1 || grid[r+1][c]==0)
                            count++;
                        if(r+1<=n-1 && !vis[r+1][c] && grid[r+1][c])
                        {
                            vis[r+1][c]=1;
                            q.push({r+1,c});
                        }
                        if(c+1>m-1 || grid[r][c+1]==0)
                            count++;
                        if(c+1<=m-1 && !vis[r][c+1] && grid[r][c+1])
                        {
                            vis[r][c+1]=1;
                            q.push({r,c+1});
                        }
                    }
                }
            }
        }
        return count;
    }
};