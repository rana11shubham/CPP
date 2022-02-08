// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    void solve(string str,string &ans,int pos,int k){
        if(k==0)return;
        if(pos==str.length())return;
        char temp=str[pos];
        for(int i=pos+1;i<str.length();i++){
            if(str[i]>temp)
                temp=str[i];
        }
        if(temp!=str[pos]){
            k--;
        }
        for(int j=str.length()-1;j>=pos;j--){
            if(temp==str[j]){
                swap(str[j],str[pos]);
                if(str.compare(ans)>0)
                    ans=str;
                solve(str,ans,pos+1,k);
                swap(str[j],str[pos]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       int n=str.size();
       string ans=str;
       solve(str,ans,0,k);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends