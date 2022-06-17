// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string,int>mp;
    vector<string>ans;
    void solve(string s,int n,string temp){
        // Base case
        
        if(s==""){
            temp=temp.substr(0,temp.length()-1);
            ans.push_back(temp);
            return;
        }
        
        for(auto it:mp){
            int len=it.first.length();
            string temp1=s.substr(0,len);
            if(it.first==temp1){
                solve(s.substr(len),n,temp+temp1+" ");
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        for(auto it:dict)
            mp[it]=1;
        solve(s,n,"");
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends