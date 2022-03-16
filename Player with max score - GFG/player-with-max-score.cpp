// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int dp[1001][1001];
    int solve(int arr[],int pos1,int pos2,int sum){
        if(pos1==pos2){
            return arr[pos1];
        }
        else if(pos2==pos1+1){
            return max(arr[pos1],arr[pos2]);
        }
        else if(pos1>pos2)
            return 0;
        else if(dp[pos1][pos2]!=-1){
            return dp[pos1][pos2];
        }
       
            dp[pos1][pos2]=max(sum-solve(arr,pos1+1,pos2,sum-arr[pos1]),sum-solve(arr,pos1,pos2-1,sum-arr[pos2]));
        
        return dp[pos1][pos2];
    }
    
    bool is1winner(int N,int arr[]) {
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
        // code here
        memset(dp,-1,sizeof(dp));
        int ans=solve(arr,0,N-1,sum);
        //cout<<ans<<endl;
        return ans>=sum-ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends