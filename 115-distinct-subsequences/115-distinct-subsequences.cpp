class Solution {
public:
    string S,T;
    int N,M;
    vector<vector<int>>dp;
    int solve(int idx1,int idx2){
        // Base Cases
          if(idx2==M)
            return 1;
        if(idx1>=N)
            return 0;
      if(dp[idx1][idx2]!=-1)
          return dp[idx1][idx2];
        
        
        if(S[idx1]==T[idx2])
            return dp[idx1][idx2]= solve(idx1+1,idx2+1)+solve(idx1+1,idx2);
        return dp[idx1][idx2]= solve(idx1+1,idx2);
    }
    int numDistinct(string s, string t) {
      int slen=s.length();
      int tlen=t.length();
      dp.resize(slen+1,vector<int>(tlen+1,-1));
      N=slen;
      M=tlen;
      S=s;
      T=t;
      return solve(0,0);
    }
};