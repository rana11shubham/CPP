// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {  int n=s.length();
       int i=0,j=0,start=0,ans=INT_MAX;
       string f_ans="";
       vector<int>mp(128,0);
       for(auto it:t)
            mp[it]++;
        int count=t.length();
        for(;j<n;j++){
            
            if(mp[s[j]]>0){
                count--;
            }
            mp[s[j]]--;
            while(count==0){
                if(ans>j-i+1){
                    ans=j-i+1;
                    start=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count++;
                }
                i++;
            }
        }
        return ans==INT_MAX?"-1":s.substr(start,ans);
        
    }
};






// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends