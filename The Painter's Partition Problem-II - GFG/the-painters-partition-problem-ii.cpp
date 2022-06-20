// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    #define ll long long
    bool valid(int arr[],int n,int k,ll mid){
        long long sum=0;
        int count=1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mid){
                count++;
                sum=arr[i];
            }
            if(count>k)
            return false;
        }
      return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        ll start=0,end=0;
       // sort(arr,arr+n);
        for(int i=0;i<n;i++){
            start=max((ll)arr[i],start);
            end+=arr[i];
        }
        long long ans=-1;
        while(start<=end){
            ll mid=start+(end-start)/2;
            if(valid(arr,n,k,mid)){
                // something to do here
                end=mid-1;
                ans=mid;
            }
            else {
                // something else to be done here
                start=mid+1;
            }
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