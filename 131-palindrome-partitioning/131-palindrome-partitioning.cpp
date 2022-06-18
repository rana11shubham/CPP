class Solution {
public:
    vector<vector<string>>result;
    // This solve tells me from idx to n, how many palindromic strings could be generated
    bool palindrome(string s){
        int n=s.length();
        if(n==1)
            return true;
        for(int i=0,j=n-1;i<j;i++,j--)
            if(s[i]!=s[j])
                return false;
        return true;
    }
    void solve(string s,int n,int idx,vector<string>&temp){
        // Base case
        if(idx==n){
            result.push_back(temp);
            return;
        }
        
        
        for(int i=idx;i<n;i++){
            if(palindrome(s.substr(idx,i-idx+1))){
               // cout<<s.substr(idx,(idx-i+1))<<endl;
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,n,i+1,temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
      int n=s.length();
      vector<string>temp;
      solve(s,n,0,temp);
      return result;
    }
};