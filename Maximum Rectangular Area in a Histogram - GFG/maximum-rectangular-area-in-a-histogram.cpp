// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    #define ll long long
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        ll ans=0;
        stack<ll>st;
        stack<ll>st1;
        vector<int>left;
        vector<int>right(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty()){
                left.push_back(i+1);
            }
            else{
                left.push_back(i-st.top());
            }
            st.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!st1.empty() and arr[st1.top()]>=arr[i])
                st1.pop();
            if(st1.empty()){
                right[i]=(n-i);
            }
            else{
                right[i]=(st1.top()-i);
            }
            st1.push(i);
        }
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]+left[i]-1)*arr[i]);
        }
        // for(auto it:right)
        //     cout<<it<<endl;
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends