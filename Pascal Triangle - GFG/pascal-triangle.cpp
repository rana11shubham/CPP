// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
#define mod 1000000007
    vector<ll> nthRowOfPascalTriangle(int n) {
        if(n==1)
            return {1};
        if(n==2)
            return {1,1};
        vector<ll>prev_Pascal=nthRowOfPascalTriangle(n-1);
        vector<ll>ans;
        ans.push_back(1);
        for(int i=0;i<prev_Pascal.size()-1;i++){
            ans.push_back((prev_Pascal[i]%mod+prev_Pascal[i+1]%mod)%mod);
        }
        ans.push_back(1);
        return ans;
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends