// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    if(N==1)
	        return A[0];
	    int start=0;
	    int end=N-1;
	    if(A[0]!=A[1])
	        return A[0];
	   if(A[N-2]!=A[N-1])
	        return A[N-1];
	    while(start<=end){
	        int mid=start+(end-start)/2;
	       if(A[mid]==A[mid-1]){
	            if((mid)%2==1)
	                   start=mid+1;
	               else
	                    end=mid-1;
	       }
	       else if(A[mid]==A[mid+1])
	            {
	                if((mid)%2==1)
	                   end=mid-1;
	               else
	                    start=mid+1;
	            }
	       else return A[mid];
	       }
	    return -1;
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends