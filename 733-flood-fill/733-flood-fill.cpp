class Solution {
public:
        int visited[101][101];
    int dp[101][101];
    void solve(vector<vector<int>>&image,int x,int y,int C,int r,int c){
        if(x<0 | x>r)return;
        if(y<0 | y>c)return;
        if((x+1)<r){
            if(image[x][y]==image[x+1][y] && visited[x+1][y]!=true){
                dp[x+1][y]=C,visited[x+1][y]=true;
                solve(image,x+1,y,C,r,c);
            }
        }
        if((x-1)>=0){
            if(image[x][y]==image[x-1][y] && visited[x-1][y]!=true){
                dp[x-1][y]=C,visited[x-1][y]=true;
                solve(image,x-1,y,C,r,c);
            }
        }
            if((y+1)<c){
                if(image[x][y]==image[x][y+1] && visited[x][y+1]!=true){
                dp[x][y+1]=C,visited[x][y+1]=true;
                solve(image,x,y+1,C,r,c);
            }
        }
            if((y-1)>=0){
                if(image[x][y]==image[x][y-1] && visited[x][y-1]!=true){
                dp[x][y-1]=C,visited[x][y-1]=true;
                solve(image,x,y-1,C,r,c);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int row=image.size();
        int col=image[0].size();
        memset(visited,false,sizeof(visited));
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                dp[i][j]=image[i][j];
        dp[sr][sc]=newColor;
        visited[sr][sc]=true;
        solve(image,sr,sc,newColor,row,col);
        vector<vector<int>>ans(row,vector<int>(col));
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                ans[i][j]=dp[i][j];
        return ans;
    }
};