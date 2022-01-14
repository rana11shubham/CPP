// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isVerify(int arr[],long long X,int n,int k){
        int painter=1,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>X){
                painter++;
                sum=arr[i];
            }
            if(painter>k){
                return false;
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long S=0,E=0;
        for(int i=0;i<n;i++){
            S=max(S,(long long)arr[i]);
            E+=arr[i];
        }
        long long ans=0;
        while(S<=E){
            long long mid=S+(E-S)/2;
            if(isVerify(arr,mid,n,k)){
                E=mid-1;
                ans=mid;
            }
            else
                S=mid+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends