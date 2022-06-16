// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void solve(vector<vector<int>> &m, int n,int r,int c,string s){
        // base case
        if(r==n-1 and c==n-1 and m[r][c]!=0){
            ans.push_back(s);
            return;
        }
        if(r<0 || r>=n || c<0 || c>=n || m[r][c]!=1)
            return;
        m[r][c]=-1;
        solve(m,n,r-1,c,s+"U");
        solve(m,n,r,c-1,s+"L");
        solve(m,n,r,c+1,s+"R");
        solve(m,n,r+1,c,s+"D");
        m[r][c]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        solve(m,n,0,0,"");
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