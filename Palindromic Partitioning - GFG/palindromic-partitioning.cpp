// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool isPalindrome(string &s,int x,int y){
        for(int i=x,j=y;i<y;i++,j--)
            if(s[i]!=s[j])
                return false;
        return true;
    }
    int solve(string &s,int i,int j){
        // Base Cases
        if(i>=j)
            return 0;
        if(isPalindrome(s,i,j))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int final_ans=1e9;
        for(int k=i;k<j;k++){
            int left_part=solve(s,i,k);
            int right_part=solve(s,k+1,j);
            int ans=left_part+right_part;
            final_ans=min(final_ans,1+ans);
        }
        return dp[i][j]= final_ans;
    }
    
    int palindromicPartition(string str)
    {
        int n=str.size();
        memset(dp,-1,sizeof(dp));
        return solve(str,0,n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends