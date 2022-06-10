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


int longestSubstrDistinctChars (string S)
{
    unordered_map<char,int>mp;
    int i=0,j=0;
    int ans=0;
    int n=S.length();
    while(j<n){
        char temp=S[j];
        if(mp.find(temp)!=mp.end()){
            i=max(mp[temp]+1,i);
        }
        mp[temp]=j;
        ans=max(ans,j-i+1);
        j++;
    }
    return ans;
}