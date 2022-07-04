// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    //Function to find minimum number of pages.
    bool isValid(int A[],int N,int M,int mid){
        int count=1,sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum>mid){
                count++;
                sum=A[i];
            }
            if(count>M)
                return false;
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        int s=A[N-1];
        
        int e=0;
        int ans=-1;
        for(int i=0;i<N;i++)
            e+=A[i];
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isValid(A,N,M,mid)){
                e=mid-1;
                ans=mid;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends