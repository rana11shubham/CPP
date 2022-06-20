// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	     priority_queue<int,vector<int>,greater<int>>mp(arr,arr+k);
        for(int i=k;i<n;i++){
            if(mp.top()<arr[i]){
                mp.pop();
                mp.push(arr[i]);
            }
        }
        vector<int>ans;
        while(mp.empty()!=true){
            ans.push_back(mp.top());
            mp.pop();
        }
        sort(ans.begin(),ans.end(),greater<int>());
         return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends