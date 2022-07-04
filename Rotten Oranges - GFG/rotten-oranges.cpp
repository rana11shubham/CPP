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
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(grid[i][j]==2)
            q.push({i,j});
        }
    int time=0;
    int row[]={-1,0,0,1};
    int col[]={0,-1,1,0};
    while(q.empty()!=true){
        int sz=q.size();
        int status=0;
        for(int i=0;i<sz;i++){
            auto it=q.front();
            q.pop();
            int ro=it.first;
            int co=it.second;
            for(int j=0;j<4;j++){
                if(ro+row[j]>=0 and ro+row[j]<n and co+col[j]>=0 and co+col[j]<m and grid[ro+row[j]][co+col[j]]==1){
                    grid[ro+row[j]][co+col[j]]=2;
                    q.push({ro+row[j],co+col[j]});
                    
                    status=1;
                
            }
        }
        }
        if(status)
            time++;
    }
    for(auto it:grid)
        for(auto it1:it)
            if(it1==1)
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