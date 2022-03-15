// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    #define mod 1000000007
	public:
	    int dp[10001];
	    int solve(string str){
	       int n=str.length();
	       dp[1]=1;
	       for(int i=2;i<=n;i++){
	           int x=((str[i-2]-'0')*10+(str[i-1]-'0'));
	           if(str[i-1]=='0'){
	               if(str[i-2]=='0'){
	                   dp[i]=0;
	                   return 0;
	               }
	               else{
	                   if(x>26 || x<=0){
	                       dp[i]=0;
	                       return 0;
	                   }
	                   else{
	                       dp[i]=dp[i-2];
	                   }
	               }
	           }
	           else{
	               if(str[i-2]=='0'){
	                   dp[i]=dp[i-1];
	               }
	               else{
	                   if(x>26){
	                    dp[i]=dp[i-1];
	                   }
	                    else{
	                    dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
	           
	                    }
	               }
	           }
	       }
	       return dp[n];
	    }
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    if(n==0 || str[0]=='0')
		        return 0;
		  memset(dp,0,sizeof(dp));
		  dp[0]=1;
		  return solve(str);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends