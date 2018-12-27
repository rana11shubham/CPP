#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
 for(int i=0;i<n;i++)
    cin>>a[i];
    int dp[n]={1};
    for(int i=1;i<n;i++){
    	for(int j=0;j<i;j++){
    	while(a[i]<a[j] && dp[i]<dp[j]+1 ){
    		dp[i]=dp[j]+1;
    	}
    }
    }
    int max=dp[0];
    for(int i=1;i<n;i++){
    	if(max<dp[i])
    	    max=dp[i];
    }
    cout<<max;
return 0;
}


