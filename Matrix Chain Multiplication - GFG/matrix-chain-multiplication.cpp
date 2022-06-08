// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<vector<int>>dp;
    int solve(int arr[],int N,int i,int j){
        // Base Cases
        if(i>=j)
            return 0;
        int ans=1e9;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=i;k<j;k++){
            ans=min(ans,arr[i-1]*arr[k]*arr[j]+solve(arr,N,i,k)+solve(arr,N,k+1,j));
        }
        return dp[i][j]= ans;
    }
    int matrixMultiplication(int N, int arr[])
    {   dp.resize(N+1,vector<int>(N+1,-1));
        return solve(arr,N,1,N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends