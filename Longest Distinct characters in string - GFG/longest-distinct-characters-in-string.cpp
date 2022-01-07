// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n=s.length();
        unordered_map<char,int>mp;
        int i=0,j=0,ans=0,loc_ans=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                int pos=mp[s[j]];
                if(pos>=i)
                    i=pos+1;
                ans=max(ans,j-i+1);
                loc_ans=j-i+1;
                mp[s[j]]=j;
                j++;
            }
            else{
                mp[s[j]]=j;
                j++;
                loc_ans++;
                ans=max(ans,loc_ans);
            }
        }
        return ans;
    
}