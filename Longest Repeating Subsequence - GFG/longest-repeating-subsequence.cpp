// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length();
		    int dp[n+1][n+1];
		    memset(dp,0,sizeof(dp));
		    int ans=0;
		    for(int i=1;i<=n;i++){
		        for(int j=i+1;j<=n;j++){
		            if(str[i-1]==str[j-1]){
		                dp[i][j]=1+dp[i-1][j-1];
		                ans=max(ans,dp[i][j]);
		            }
		            else{
		                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		            }
		        }
		    }
	
		
		        
		  return ans;
		}

};
/*
    axyxxy----dp(i,j)=1+dp(i+1,j+1) in case of str[i]==str[j].
              dp(i,j)= max(dp[i,j+1),dp[i+1,j]
*/




// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends