// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums[])
    {
    //   vector<int>dp(n+1,1);
    //     int ans=1;
    //     for(int i=n-2;i>=0;i--){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i]<nums[j]){
    //                 dp[i]=max(dp[i],dp[j]+1);
    //             }
    //         }
    //         ans=max(ans,dp[i]);
    //     }
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(ans.back()<nums[i]){
                ans.push_back(nums[i]);
            }
            else{
                int pos=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[pos]=nums[i];
            }
        }
        return ans.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends