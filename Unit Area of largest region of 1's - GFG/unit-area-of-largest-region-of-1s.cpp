// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
     int dfs(vector<vector<int>>&grid,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;
        int ans=0;
        ans+=dfs(grid,r-1,c);
        ans+=dfs(grid,r+1,c);
        ans+=dfs(grid,r,c-1);
        ans+=dfs(grid,r,c+1);
        ans+=dfs(grid,r+1,c+1);
        ans+=dfs(grid,r+1,c-1);
        ans+=dfs(grid,r-1,c+1);
        ans+=dfs(grid,r-1,c-1);
        return ans+1;
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                  ans=max(ans,dfs(grid,i,j)); 
                }
            }
        }
        return ans;
        
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends