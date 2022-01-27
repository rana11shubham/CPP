// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
long long  numberOfPaths(int m, int n)
{
    // Code Here
    long long dp[m][n]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0){
                dp[i][j]=1;
            }
            else if(j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
    }
    return dp[m-1][n-1];
}

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends