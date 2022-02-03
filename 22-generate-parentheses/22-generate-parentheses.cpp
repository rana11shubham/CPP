class Solution {
public:
    vector<string>ans;
    void solve(int n,int pos,string res){
      if(n==0 && pos==0){
          ans.push_back(res);
          return;
      }
        if(n>0){
        solve(n-1,pos+1,res+"(");
        }
        if(pos>0){
        solve(n,pos-1,res+")");
        }
        }
    vector<string> generateParenthesis(int n) {
       if(n==0)
           return {};
        solve(n,0,"");
        return ans;
    }
};