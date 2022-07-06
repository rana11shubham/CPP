// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
    //   deque<int>dq;
    //   vector<int>result;
    //   for(int i=0;i<k;i++){
    //       while(!dq.empty() and arr[dq.back()]<=arr[i]){
    //           dq.pop_back();
    //       }
    //       dq.push_back(i);
    //   }
    //   result.push_back(arr[dq.front()]);
    //   for(int i=k;i<n;i++){
          
    //       while(!dq.empty() and dq.front()<=i-k){
    //           dq.pop_front();
    //       }
    //       while(!dq.empty() and arr[dq.back()]<=arr[i])
    //         dq.pop_back();
    //       dq.push_back(i);
    //       result.push_back(arr[dq.front()]);
    //   }
    //     return result;
    multiset<int>mp;
       //int n=nums.size();
       vector<int>dp;
        //mp.insert(dp[0]);
       for(int i=0;i<n;i++){
           if(i>=k-1){
               mp.insert(nums[i]);
               dp.push_back(*rbegin(mp));
               mp.erase(mp.find(nums[i-k+1]));
               
              
           }
           else
          mp.insert(nums[i]);
       }
        return dp;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends