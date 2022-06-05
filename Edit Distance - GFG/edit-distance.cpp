// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  string S,T;
  int N,M;
  vector<vector<int>>dp;
    int solve(int idx1,int idx2){
        // Base Cases
        if(idx1<0)
            return idx2+1;
        if(idx2<0)
            return idx1+1;
        int &ans=dp[idx1][idx2];
        if(ans!=-1)
            return ans;
        if(S[idx1]==T[idx2]){
            return ans= solve(idx1-1,idx2-1);
        }
        int opt1=1+solve(idx1-1,idx2);
        int opt2=1+solve(idx1,idx2-1);
        int opt3=1+solve(idx1-1,idx2-1);
        return ans= min(opt1,min(opt2,opt3));
    }
    int editDistance(string s, string t) {
        S=s;
        T=t;
        N=s.length();
        M=t.length();
        if(N==0)
            return M;
        else if(M==0)
            return N;
        dp.resize(N+1,vector<int>(M+1,-1));
        return solve(N-1,M-1);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends