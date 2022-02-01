// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string>ans;
	    void solve(string S,int n,int pos){
	        if(pos==n){
	            ans.push_back(S);
	            return;
	        }
	        for(int i=pos;i<n;i++){
	            swap(S[pos],S[i]);
	            solve(S,n,pos+1);
	            swap(S[pos],S[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		   int n=S.length();
		   solve(S,n,0);
		   sort(ans.begin(),ans.end());
		    return ans;
		    
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends