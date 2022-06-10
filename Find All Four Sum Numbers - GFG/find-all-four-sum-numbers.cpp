// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
         sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<vector<int>>ans;
        if(n<4)
            return ans;
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               int tar=target-(nums[i]+nums[j]);
               int l=j+1;
               int r=n-1;
               while(l<r){
                   if(nums[l]+nums[r]>tar)
                       r--;
                   else if(nums[l]+nums[r]<tar){
                       l++;
                   }
                   else{
                       vector<int>q(4,0);
                       q[0]=nums[i];
                       q[1]=nums[j];
                       q[2]=nums[l];
                       q[3]=nums[r];
                       ans.push_back(q);
                        while(l<r && q[2]==nums[l]){
                            l++;
                        }
                        while(l<r && q[3]==nums[r]){
                            r--;
                        }
                   }
               }
               while(j+1<n and nums[j]==nums[j+1])
                   j++;
           }
           while(i+1<n and nums[i]==nums[i+1])
                   i++;
       }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends