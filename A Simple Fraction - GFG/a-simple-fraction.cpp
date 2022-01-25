// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    // Code here
	    unordered_map<int,int>mp;
	    int quotient=numerator/denominator;
	    int rem=numerator%denominator;
	    string ans;
	    ans=(to_string(quotient));
	    if(rem==0){
	        return ans;
	    }
	    ans.push_back('.');
	    while(rem!=0){
	        int temp=rem*10;
	        
	        if(mp.find(temp)!=mp.end()){
	            int pos=mp[temp];
	            ans=ans.substr(0,pos)+"("+ans.substr(pos)+")";
	            break;
	        }
	        mp[temp]=ans.size();
	        quotient=temp/denominator;
	        ans.push_back(quotient+'0');
	        rem=temp%denominator;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends