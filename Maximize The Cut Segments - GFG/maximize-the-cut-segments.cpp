// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    int dp[100000];
    //Function to find the maximum number of cuts.
    int solve(int n,int *possible_cut){
        // Base case
        if(n==0)
            return 0;
            if(dp[n]!=-1)
                return dp[n];
        int ans=INT_MIN;
        for(int i=0;i<3;i++){
            if(possible_cut[i]<=n){
                int temp=solve(n-possible_cut[i],possible_cut);
                if(temp!=INT_MIN){
                ans=max(ans,temp+1);
                }
                
            }
        }
        return dp[n]=ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
       int possible_cut[3]={x,y,z};
       memset(dp,-1,sizeof(dp));
      int ans= solve(n,possible_cut);
    
        return ans==INT_MIN?0:ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends