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
    set<vector<int>>ans;
    void solve(vector<int>&A,int B,int idx,vector<int>&result){
        // Base cases
        if(B==0)
            {   sort(result.begin(),result.end());
                ans.insert(result);
                return;
            }
        if(B<0 || idx==A.size())
            return;
        result.push_back(A[idx]);
        if(A[idx]<=B)
            solve(A,B-A[idx],idx,result);
        result.pop_back();
        solve(A,B,idx+1,result);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        int n=A.size();
        vector<int>temp;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        solve(A,B,0,temp);
        vector<vector<int>>result;
        for(auto it:ans)
            result.push_back(it);
        return result;
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