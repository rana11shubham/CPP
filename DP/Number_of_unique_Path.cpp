//https://practice.geeksforgeeks.org/problems/number-of-unique-paths/0
//Simple DP solution

#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,m,n;
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    vector<vector<int>>dp;
	    dp.resize(m,vector<int>(n,0));
	    for(int i=0;i<m;i++){
	        dp[i][n-1]=1;
	    }
	    for(int i=0;i<n;i++){
	        dp[m-1][i]=1;
	    }
	    for(int i=m-2;i>=0;i--){
	        for(int j=n-2;j>=0;j--){
	            dp[i][j]=dp[i+1][j]+dp[i][j+1];
	        }
	    }
	    cout<<dp[0][0]<<endl;
	}
	return 0;
}
