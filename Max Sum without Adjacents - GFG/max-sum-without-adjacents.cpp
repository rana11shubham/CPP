// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	vector<int>dp;
	int solve(int *arr,int n,int i){
	    // Base cases
	    if(i>=n)
	        return 0;
	    
	    if(dp[i]!=-1)
	        return dp[i];
	    int opt1=solve(arr,n,i+1);
	    int opt2=solve(arr,n,i+2)+arr[i];
	    return dp[i]= max(opt1,opt2);
	}
	int findMaxSum(int *arr, int n) {
	    dp.assign(n,-1);
	    return solve(arr,n,0);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends