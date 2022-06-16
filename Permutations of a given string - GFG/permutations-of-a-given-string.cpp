// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	   set<string>ans;
	    void solve(string S,int n,int pos){
	        if(pos==n){
	            ans.insert(S);
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
		   vector<string>final_ans;
		   for(auto it:ans)
		    final_ans.push_back(it);
		   sort(final_ans.begin(),final_ans.end());
		    return final_ans;
		    
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