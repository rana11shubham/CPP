class Solution {
public:
    string lcs(string s1,string s2){
        int n=s1.length();
        int m=s2.length();
        vector<vector<string>>dp(n+1,vector<string>(m+1,""));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }
                else{
                    if(dp[i-1][j].length()>dp[i][j-1].length()){
                        dp[i][j]=dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i][j-1];
                    }
                }
            }
        }
        return dp[n][m];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        int i=0,j=0;
        string res="";
        string lcs_string=lcs(str1,str2);
        for(char c:lcs_string){
            while(str1[i]!=c){
                res+=str1[i];
                i++;
            }
            while(str2[j]!=c){
                res+=str2[j];
                j++;
            }
            res+=c;
            i++;
            j++;
        }
        while(i<n){
            res+=str1[i];
            i++;
        }
         while(j<m){
            res+=str2[j];
             j++;
        }
        return res;
    }
};