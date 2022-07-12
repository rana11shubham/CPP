// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        set<vector<int>>ans;
        for(int i=0;i<(1<<n);i++){
            vector<int>result;
            for(int j=0;j<n;j++)
            {
                if((i>>j) & 1){
                    result.push_back(arr[j]);
                }
            }
            sort(result.begin(),result.end());
            ans.insert(result);
        }
        vector<vector<int>>ans1;
        for(auto it:ans){
            ans1.push_back(it);
        }
        return ans1;
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
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
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
}   


  // } Driver Code Ends