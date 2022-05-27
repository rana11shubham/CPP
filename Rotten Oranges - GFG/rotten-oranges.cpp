// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
     int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
         queue<pair<int,int>>q;
        int time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                   
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
                    while(!q.empty()){
                        int qs=q.size();
                         int status=0;
                        for(int x=0;x<qs;x++){
                        auto it=q.front();
                        q.pop();
                        int r=it.first;
                        int c=it.second;
                        if(r-1>=0 && grid[r-1][c]==1 && !vis[r-1][c]){
                            vis[r-1][c]=true;
                            q.push({r-1,c});
                            grid[r-1][c]=2;
                            status=1;
                        }
                         if(r+1<n && grid[r+1][c]==1 && !vis[r+1][c]){
                            vis[r+1][c]=true;
                            q.push({r+1,c});
                             grid[r+1][c]=2;
                             status=1;
                        }
                         if(c-1>=0 && grid[r][c-1]==1 && !vis[r][c-1]){
                            vis[r][c-1]=true;
                            q.push({r,c-1});
                             grid[r][c-1]=2;
                            status=1;
                         }
                         if(c+1<m && grid[r][c+1]==1 && !vis[r][c+1]){
                            vis[r][c+1]=true;
                            q.push({r,c+1});
                             grid[r][c+1]=2;
                             status=1;
                        }
                    }
                    if(status)
                    time++;
                }
                        
       
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    return -1;
        return time;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends