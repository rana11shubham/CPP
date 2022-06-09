// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int solve(string &S,int i,int j,bool T){
        // Base Case
        if(i>j)
            return 0;
        if(i==j){
            if(T==true)
                return S[i]=='T';
            return S[i]=='F';
        }
        if(dp[i][j][T]!=-1)
            return dp[i][j][T];
        int ans=0;
        int temp=0;
        for(int k=i+1;k<j;k+=2){
            int l_true=solve(S,i,k-1,true);
            int l_false=solve(S,i,k-1,false);
            int r_true=solve(S,k+1,j,true);
            int r_false=solve(S,k+1,j,false);
            if(S[k]=='|'){
                if(T==true)
                temp+=l_true*r_true+l_false*r_true+l_true*r_false;
                else
                temp+=l_false*r_false;
            }
            else if(S[k]=='&'){
                if(T==true)
                temp+=l_true*r_true;
                else
                    temp+=l_false*r_false+l_true*r_false+l_false*r_true;
            }
            else if(S[k]=='^'){
                if(T==true)
                temp+= l_true*r_false+l_false*r_true;
                else
                    temp+=l_true*r_true+l_false*r_false;
            }
        }
        ans+=temp;
        return dp[i][j][T]= ans%1003;
    }
    int countWays(int N, string S){
        memset(dp,-1,sizeof(dp));
        return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends