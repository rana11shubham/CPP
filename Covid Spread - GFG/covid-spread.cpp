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
         int r=grid.size();
         int c=grid[0].size();
         queue<pair<int,int>>q;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
         int time=0;
         int row[]={-1,0,0,1};
         int col[]={0,-1,1,0};
         while(q.empty()!=true){
             int n=q.size();
              int status=1;
             for(int i=0;i<n;i++){
                 auto it=q.front();
                 q.pop();
                 int ro=it.first;
                 int co=it.second;
                 for(int j=0;j<4;j++){
                     if(ro+row[j]>=0 and ro+row[j]<r and co+col[j]>=0 and co+col[j]<c and grid[ro+row[j]][co+col[j]]==1)
                        {
                            grid[ro+row[j]][co+col[j]]=2;
                            q.push({ro+row[j],co+col[j]});
                            status=0;
                        }
                 }
             }
             if(status==0)
             time++;
         }
         for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
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