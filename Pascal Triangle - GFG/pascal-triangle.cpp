// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
#define mod 1000000007
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1){
            return {1};
        }
        else if(n==2)
            return {1,1};
        vector<ll>temp=nthRowOfPascalTriangle(n-1);
        vector<ll>ans;
        ans.push_back(1);
        for(int i=0;i<temp.size()-1;i++){
            ans.push_back((ll)(temp[i]+temp[i+1])%mod);
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