// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> grid)
    {
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


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends