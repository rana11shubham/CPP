// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    typedef long long ll;
    //  #define inf 1e+7
    // ll dp[1001][1001][1001];
    // bool vis[1001][1001][1001];
    // ll solve(int i,int j,int n){
    //     if(n==0){
    //         return 0;
    //     }
    //     if(n<0){
    //         return -inf; 
    //     }
    //     if(vis[i][j][n]==true){
    //         return -inf;
    //     }
    //     cout<<"fdf";
    //     vis[i][j][n]=true;
    //     ll opt1=2*i+solve(i+i,i,n-2);
    //     ll opt2=i+j+solve(i+j,j,n-1);
    //     ll opt3=1+i+solve(i+1,j,n-1);
    //     return max(opt1,max(opt2,opt3));
    // }
    long long dp[10000];
    long long int optimalKeys(int N){
        // code here
    //   memset(dp,-1,sizeof(dp));
    //   memset(vis,false,sizeof(vis));
    //  return 1+solve(1,0,N);
    if(N<=6){
        return N;
    }
    if(dp[N]!=0){
        return dp[N];
    }
    int ans=0;
    for(int i=N-3;i>=1;i--){
        int temp=(N-(i+2)+1)*optimalKeys(i);
        ans=max(ans,temp);
    }
    return dp[N]= ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends