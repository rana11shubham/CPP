// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	#define mod 1000000007
	vector<vector<int>>dp;
	int solve(int arr[],int n,int idx,int sum){
	     if(idx==n-1)
	       if(sum==0 and arr[idx]==0)
	        return 2;
	    if(sum==0){
	        return 1;
	    }
	   
	    if(sum<0)
	        return 0;
	    if(idx==n)
	        return 0;
	   if(dp[idx][sum]!=-1)
	        return dp[idx][sum];
	   int opt1=solve(arr,n,idx+1,sum)%mod;
	   int opt2=solve(arr,n,idx+1,sum-arr[idx])%mod;
	   return dp[idx][sum]=(opt1+opt2)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{ dp.assign(n,vector<int>(sum+1,-1));
       return solve(arr,n,0,sum); 
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends