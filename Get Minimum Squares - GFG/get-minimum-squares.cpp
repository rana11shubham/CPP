// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int dp[100000];
	int solve(int n){
	    if(n==1)
	        return 1;
	   if(n<=0)
	        return 0;
	   if(dp[n]!=-1)
	        return dp[n];
	    int ans=INT_MAX;
	   for(int i=sqrt(n);i>=1;i--){
	       int temp=solve(n-i*i)+1;
	       ans=min(ans,temp);
	   }
	   return dp[n]= ans;
	}
	int MinSquares(int n)
	{   memset(dp,-1,sizeof(dp));
	    return solve(n);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends