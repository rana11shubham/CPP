// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	   vector<pair<int,int>>dp(n);
	   int sum=0;
	   dp[n-1]={1,arr[n-1]};
	   for(int i=n-2;i>=0;i--){
	       int temp=0,len=0;
	       for(int j=i+1;j<n;j++){
	           if(arr[i]<arr[j]){
	               if(len<=dp[j].first){
	               len=dp[j].first;
	                temp=max(temp,dp[j].second);
	           }
	       }
	       }
	       dp[i]={1+len,temp+arr[i]};
	   }
	   for(int i=0;i<n;i++){
	       sum=max(sum,dp[i].second);
	   }
	   return sum;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends