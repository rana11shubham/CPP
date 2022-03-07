// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isPatternPresent(string S, string P) {
        int n=S.length();
        int m=P.length();
        if(P[0]=='^'){
            if(n<m-1){
                return 0;
            }
            string temp1=S.substr(0,m-1);
            string temp2=P.substr(1);
           if(temp1!=temp2){
            return 0;}
            
            return 1;
        }
        else if(P[m-1]=='$'){
            if(n<m-1){
                return 0;
            }
            string temp=S.substr(n-m+1);
            string temp1=P.substr(0,m-1);
            if(temp==temp1)
                return 1;
            return 0;
        }
        else{
            int dp[n+1][m+1];
            memset(dp,0,sizeof(dp));
            int max_ans=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++){
                    if(S[i-1]==P[j-1]){
                        dp[i][j]=dp[i-1][j-1]+1;
                        max_ans=max(max_ans,dp[i][j]);
                        
                    }
                }
            }
            return (max_ans==m)?1:0;
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string P,S;

        cin>>P;
        cin>>S;

        Solution ob;
        cout << ob.isPatternPresent(S,P) << endl;
    }
    return 0;
}  // } Driver Code Ends