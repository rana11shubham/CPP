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
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<int,vector<int>>pq(arr,arr+k);
        priority_queue<int>drop;
        vector<int>result;
        result.push_back(pq.top());
        for(int i=k;i<n;i++){
            if(arr[i-k]==pq.top()){
                pq.pop();
            }
            else{
                drop.push(arr[i-k]);
            }
            while(drop.empty()!=true and drop.top()==pq.top())
                {
                    drop.pop();
                    pq.pop();
                }
            pq.push(arr[i]);
            result.push_back(pq.top());
        }
        return result;
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