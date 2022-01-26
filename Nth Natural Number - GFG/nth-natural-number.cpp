// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


class Solution{
	public:
    	long long findNth(long long N)
    {
        long long quotient=N/9;
        long long rem=N%9;
        long long ans=rem;
        int i=1;
        while(quotient>=1){
            rem=quotient%9;
            quotient=quotient/9;
            
            ans+=rem*pow(10,i);
            i++;
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
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}

  // } Driver Code Ends