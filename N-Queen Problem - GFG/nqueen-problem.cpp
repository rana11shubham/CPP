// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>ans;
    static int m;
    bool isValid(int grid[][10],int row,int col,int n){
        for(int i=row,j=0;j<col;j++) // checked row
            if(grid[i][j]==1)
                return false;
        for(int i=0,j=col;i<row;i++) // checked col
            if(grid[i][j]==1)
                return false;
        for(int i=row-1,j=col-1;j>=0 && i>=0;j--,i--) // checked upper left diagonal
            if(grid[i][j]==1)
                return false;
        for(int i=row-1,j=col+1;j<n && i>=0;j++,i--)
            if(grid[i][j]==1)
                return false;
        return true;
    }
    void solve(int grid[][10],int n,int row){
        if(row==n){
            vector<int>temp;
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(grid[j][i]==1)
                        temp.push_back(j+1);
            ans.push_back(temp);
        }
        for(int col=0;col<n;col++){
            if(isValid(grid,row,col,n)){
                grid[row][col]=1;
                solve(grid,n,row+1);
                grid[row][col]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        
        int grid[10][10]={{0}};
        solve(grid,n,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends