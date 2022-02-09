// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    set<vector<int>>result;
    void solve(vector<int>&A,int B,int pos,vector<int>&ans){
        if(B==0){
            sort(ans.begin(),ans.end());
            result.insert(ans);
            return;
        }
        while(pos<A.size() && B-A[pos]>=0){
            ans.push_back(A[pos]);
            solve(A,B-A[pos],pos,ans);
            pos++;
             ans.pop_back();
        }
        
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        int n=A.size();
        vector<int>ans;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        solve(A,B,0,ans);
        vector<vector<int>>res;
        for(auto it:result)
            res.push_back(it);
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends