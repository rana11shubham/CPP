// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	vector<vector<int>>dp;
	int solve(int coins[],int idx,int V,int M){
	    // Base Cases
	    if(idx==M-1){
	        if(V%coins[idx]==0)
	            return V/coins[idx];
	       return 1e9+7;
	    }
	   if(V==0)
	    return 0;
	   if(V<0)
	    return 1e9+7;
	    if(dp[idx][V]!=-1)
	        return dp[idx][V];
	    int opt1=1+solve(coins,idx,V-coins[idx],M);
	    int opt2=solve(coins,idx+1,V,M);
	    return dp[idx][V]= min(opt1,opt2);
	}
	
	
	int minCoins(int coins[], int M, int V) 
	{   dp.assign(M,vector<int>(V+1,-1));
	    int ans= solve(coins,0,V,M);
	   return ans==1e9+7?-1:ans;
	    
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