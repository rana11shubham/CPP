// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>dp;
    int solve(int val[],int wt[],int N,int idx,int W){
        // Base Cases
        if(W<0){
            return -1e9;
        }
        if(W==0)
            return 0;
        if(idx>=N)
            return 0;
        if(dp[idx][W]!=-1)
            return dp[idx][W];
        int opt1=solve(val,wt,N,idx+1,W);
        int opt2=solve(val,wt,N,idx,W-wt[idx])+val[idx];
        return dp[idx][W]= max(opt1,opt2);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {   dp.resize(N,vector<int>(W+1,-1));
        return solve(val,wt,N,0,W);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends