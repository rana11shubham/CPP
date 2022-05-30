// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n=Matrix.size();
        int m=Matrix[0].size();
        int ans=0;
        if(n==1){
            for(int i=0;i<n;i++)
                ans=max(ans,Matrix[0][i]);
            return ans;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int sum1=0,sum2=0,sum3=0;
                if(i-1>=0){
                    sum1=Matrix[i][j]+Matrix[i-1][j];
                }
                if(i-1>=0 && j-1>=0){
                    sum2=Matrix[i][j]+Matrix[i-1][j-1];
                }
                if(i-1>=0 && j+1<m){
                    sum3=Matrix[i][j]+Matrix[i-1][j+1];
                }
                Matrix[i][j]=max(sum1,max(sum2,sum3));
                if(i==n-1)
                    ans=max(Matrix[i][j],ans);
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends