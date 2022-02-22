// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int dp[100000];
	int solve(int *coins,int n,int v){
	    //Base case
	    if(v==0)
	        return 0;
	  
	    if(dp[v]!=-1)
	        return dp[v];
	    int ans=INT_MAX;
	    for(int i=0;i<n;i++){
	        if(coins[i]<=v){
	        int temp=solve(coins,n,v-coins[i]);
	        if(temp!=INT_MAX)
	            ans=min(ans,temp+1);
	        }
	    }
	    
	   return dp[v]=ans;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    memset(dp,-1,sizeof(dp));
	    int ans=solve(coins,M,V);
	    return ans==INT_MAX?-1:ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends