// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    #define mod 1000000007
    vector<vector<int>>dp;
    unordered_map<int,int>mp;
    int solve(int x,int y,int n,int m,vector<vector<int>>&grid){
        // Base cases
         if(x<0 || x>=n || y<0 || y>=m)
            return 0;
       
         if(grid[x][y]==1){
            return 0;
        }
        if(x==n-1 && y==m-1)
            return 1;
       
        if(dp[x][y]!=-1)
            return dp[x][y];
            
        int rightWay=solve(x,y+1,n,m,grid)%mod;
        int downWay=solve(x+1,y,n,m,grid)%mod;
        return dp[x][y]=(rightWay%mod+downWay%mod)%mod;
    }
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    dp.resize(n,vector<int>(m,-1));
	    vector<vector<int>>grid(n,vector<int>(m,0));
	    for(auto it:blocked_cells)
	        grid[it[0]-1][it[1]-1]=1;
	        //mp[(it[0]-1)*10+(it[1]-1)]=1;
	    return solve(0,0,n,m,grid);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends