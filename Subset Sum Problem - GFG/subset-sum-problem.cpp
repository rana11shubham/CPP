// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
vector<vector<int>>dp;
    bool solve(vector<int>arr,int idx,int sum){
        // Base cases
        if(idx==arr.size()-1)
            return sum==arr[idx];
        if(sum==0)
            return true;
        if(sum<0)
            return false;
        int &ans=dp[idx][sum];
        if(ans!=-1)
            return ans;
        int opt1=solve(arr,idx+1,sum);
        int opt2=solve(arr,idx+1,sum-arr[idx]);
        return ans=( opt1||opt2);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        dp.assign(arr.size(),vector<int>(sum+1,-1));
        return solve(arr,0,sum);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends