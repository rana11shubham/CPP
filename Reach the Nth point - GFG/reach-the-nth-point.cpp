// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    long long dp[1000000];
	    int solve(int n){
	         // Code here
		    if(n==2)
		        return dp[n]=2;
		    if(n==1)
		        return dp[n]=1;
		    if(n<=0)
		        return 0;
		    if(dp[n]!=-1)
		        return dp[n];
		    return dp[n]=(solve(n-1)+solve(n-2))%1000000007;
	    }
		int nthPoint(int n){
		   memset(dp,-1,sizeof(dp));
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
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends