class Solution {
public:
    string S,P;
    int N,M;
    vector<vector<int>>dp;
    int solve(int idx1,int idx2){
        // Base Cases
        if(idx1<0 and idx2<0)
            return true;
        if(idx2<0)
            return false;
        
        if(idx1<0){
            for(int i=idx2;i>=0;i--)
                if(P[i]!='*')
                    return false;
            return true;
        }
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(S[idx1]==P[idx2] || P[idx2]=='?'){
            return dp[idx1][idx2]= solve(idx1-1,idx2-1);
        }
        else if(P[idx2]=='*')
        return dp[idx1][idx2]=solve(idx1,idx2-1) || solve(idx1-1,idx2);
        return dp[idx1][idx2]= false;
    }
    bool isMatch(string s, string p) {
        S=s;
        P=p;
        N=s.length();
        M=p.length();
        dp.resize(N+1,vector<int>(M+1,-1));
        return solve(N-1,M-1);
    }
};