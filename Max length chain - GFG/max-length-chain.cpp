// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool compar(struct val a,struct val b){
    return a.first<b.first;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
        vector<int>dp(n,0);
        sort(p,p+n,compar);
        dp[n-1]=1;
        int ans=1;
        for(int i=n-2;i>=0;i--){
            int b=p[i].second;
           for(int j=i+1;j<n;j++){
               int c=p[j].first;
               if(b<c){
                   dp[i]=max(dp[i],1+dp[j]);
                   ans=max(ans,dp[i]);
               }
           }
        }
        return ans;
}