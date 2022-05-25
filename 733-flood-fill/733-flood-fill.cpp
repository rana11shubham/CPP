class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(q.empty()!=true){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            int col=image[r][c];
            // Upward direction
            if(r-1>=0 && !vis[r-1][c] && col==image[r-1][c]){
                vis[r-1][c]=1;
                q.push({r-1,c});
            }
             if(r+1<=n-1 && !vis[r+1][c] && col==image[r+1][c]){
                vis[r+1][c]=1;
                q.push({r+1,c});
            }
             if(c-1>=0 && !vis[r][c-1] && col==image[r][c-1]){
                vis[r][c-1]=1;
                q.push({r,c-1});
            }
             if(c+1<=m-1 && !vis[r][c+1] && col==image[r][c+1]){
                vis[r][c+1]=1;
                q.push({r,c+1});
            }
            image[r][c]=newColor;
        }
        return image;
    }
};