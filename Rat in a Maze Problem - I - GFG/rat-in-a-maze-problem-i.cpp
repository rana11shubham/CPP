// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    bool vis[6][6];
    void solve(int i,int j,int n,vector<vector<int>>&m,string s){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        if(i<0 || j<0 || i>=n || j>=n || vis[i][j] || m[i][j]==0)return;
        vis[i][j]=true;
        solve(i-1,j,n,m,s+'U');
        solve(i,j-1,n,m,s+'L');
        solve(i,j+1,n,m,s+'R');
        solve(i+1,j,n,m,s+'D');
        vis[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        memset(vis,false,sizeof(vis));
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return {"-1"};
        solve(0,0,n,m,"");
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends