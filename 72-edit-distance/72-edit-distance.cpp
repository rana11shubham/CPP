class Solution {
public:
    int dp[505][505];
    int solve(string x,string y,int i,int j){
        //Base case
        if(i==-1){
            return j+1;
        }
        if(j==-1){
            return i+1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(x[i]==y[j]){
            return solve(x,y,i-1,j-1);
        }
        int insert=solve(x,y,i-1,j)+1;
        int del=solve(x,y,i,j-1)+1;
        int replace=solve(x,y,i-1,j-1)+1;
        return dp[i][j]=min(min(insert,del),replace);
        }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,word1.size()-1,word2.size()-1);
    }
};