// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        int ans=0,idx=0,reach=0,max_reachable=0;
        for(int i=0;i<N;i++){
            int reach=A[i];
            if(reach==0)
                return 0;
            if(i+A[i]>=N-1){
                return 1;
            }
             max_reachable=0,idx=0;
            for(int j=i+1;j<=i+reach&&j<N;j++){
                if(max_reachable<=A[j]){
                    max_reachable=A[j];
                    idx=j;
                }
            }
            i=idx-1;
            
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends