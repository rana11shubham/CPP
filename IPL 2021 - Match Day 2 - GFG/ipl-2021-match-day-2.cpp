// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int>q;
        int i=0,j=0;
        vector<int>ans;
        while(j<n){
                if(!q.empty()){
                int temp=q.back();
                if(arr[j]>temp){
                    while(!q.empty() and arr[j]>q.back()){
                        q.pop_back();
                    }
                    q.push_back(arr[j]);
                }
                else{
                    q.push_back(arr[j]);
                }
            }
            if(q.empty())
                q.push_back(arr[j]);
                
        
             if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                ans.push_back(q.front());
                if(q.front()==arr[i])
                    q.pop_front();

                i++;
                j++;
            }
        }
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

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends