class Solution {
public:
    int dp[101][101][201];
    bool solve(string& s1,string& s2,string& s3,int i,int j,int k){
        // Base case
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        if(i==n1 and k==n3 and j==n2){
            return true;
        }
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        bool opt1=false;
        bool opt2=false;
        if(s1[i]==s3[k]){
            opt1=solve(s1,s2,s3,i+1,j,k+1);
        }
        if(s2[j]==s3[k]){
            opt2=solve(s1,s2,s3,i,j+1,k+1);
        }
        return dp[i][j][k]= opt1||opt2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        if(n1+n2!=n3)
            return false;
        if(n1==0 and n2==0 and n3==0)
            return true;
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,0,0,0);
    }
};