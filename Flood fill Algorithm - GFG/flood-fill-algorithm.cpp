// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int visited[101][101];
    int dp[101][101];
    void solve(vector<vector<int>>&image,int x,int y,int C,int r,int c,int col){
        if(x<0 | x>r)return;
        if(y<0 | y>c)return;
        if((x+1)<r){
            if(col==image[x+1][y] && visited[x+1][y]!=true){
                image[x+1][y]=C,visited[x+1][y]=true;
                solve(image,x+1,y,C,r,c,col);
            }
        }
        if((x-1)>=0){
            if(col==image[x-1][y] && visited[x-1][y]!=true){
                image[x-1][y]=C,visited[x-1][y]=true;
                solve(image,x-1,y,C,r,c,col);
            }
        }
            if((y+1)<c){
                if(col==image[x][y+1] && visited[x][y+1]!=true){
                image[x][y+1]=C,visited[x][y+1]=true;
                solve(image,x,y+1,C,r,c,col);
            }
        }
            if((y-1)>=0){
                if(col==image[x][y-1] && visited[x][y-1]!=true){
                image[x][y-1]=C,visited[x][y-1]=true;
                solve(image,x,y-1,C,r,c,col);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int row=image.size();
        int col=image[0].size();
        memset(visited,false,sizeof(visited));
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                dp[i][j]=image[i][j];
        dp[sr][sc]=newColor;
        visited[sr][sc]=true;
        solve(image,sr,sc,newColor,row,col,image[sr][sc]);
        image[sr][sc]=newColor;
        // vector<vector<int>>ans(row,vector<int>(col));
        // for(int i=0;i<row;i++)
        //     for(int j=0;j<col;j++)
        //         ans[i][j]=dp[i][j];
        return image;
        
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends