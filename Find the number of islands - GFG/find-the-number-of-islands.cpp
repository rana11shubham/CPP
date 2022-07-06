// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int x_dir[]={-1,-1,-1,0,0,1,1,1};
        int y_dir[]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    count++;
                    queue<pair<int,int>>pq;
                    pq.push({i,j});
                    while(!pq.empty()){
                        auto it=pq.front();
                        pq.pop();
                        int r=it.first;
                        int s=it.second;
                        for(int i=0;i<8;i++){
                            if(r+x_dir[i]>=0 and r+x_dir[i]<n and s+y_dir[i]>=0 and s+y_dir[i]<m and grid[r+x_dir[i]][s+y_dir[i]]!='0'){
                                grid[r+x_dir[i]][s+y_dir[i]]='0';
                                pq.push({r+x_dir[i],s+y_dir[i]});
                            }
                        }
                        
                    }
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends