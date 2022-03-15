class Solution {
public:
    bool isMatch(string s, string p) {
        int n1=s.length();
        int n2=p.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return helper(s,p,0,0,dp);
    }
    bool helper(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        if(p.length()==j){
            return i==s.length();
        }
       if(dp[i][j]<0){
         if(i==s.length()){
                dp[i][j]= (p[j]=='*' && helper(s,p,i,j+1,dp));
                }
        else if(i<s.length() && (s[i]==p[j] || p[j]=='?')){
                dp[i][j]=helper(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='*'){
            dp[i][j]=helper(s,p,i+1,j,dp)||helper(s,p,i,j+1,dp);
        }
            else{
                dp[i][j]=false;
            }
       }
        return dp[i][j];
        }
};


/*
aabbccd
a*c?d
*/