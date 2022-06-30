// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long l=1,r=1,max_ans=INT_MIN;
	    for(int i=0;i<n;i++){
	        l*=arr[i];
	        r*=arr[n-i-1];
	        max_ans=max(max_ans,max(l,r));
	        if(l==0)
	            l=1;
	       if(r==0)
	            r=1;
	    }
	    return max_ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends