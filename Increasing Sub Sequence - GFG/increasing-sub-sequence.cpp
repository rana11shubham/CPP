// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxLength(string S)
    {
        vector<int>ans;
        ans.push_back(S[0]-'a');
        for(int i=1;i<S.length();i++){
            if(ans.back()<(S[i]-'a'))
                ans.push_back(S[i]-'a');
            else{
                int ele=S[i]-'a';
                int pos=lower_bound(ans.begin(),ans.end(),ele)-ans.begin();
                ans[pos]=S[i]-'a';
            }
            
        }
        return ans.size();
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}  // } Driver Code Ends