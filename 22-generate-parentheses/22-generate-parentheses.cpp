class Solution {
public:
    vector<string>ans;
    void generate(int n,string s,int l,int r){
        if(l==0 and r==0){
            ans.push_back(s);
            return;
        }
        if(l>0){
            generate(n,s+'(',l-1,r+1);
        }
        if(r>0){
            generate(n,s+')',l,r-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        generate(n,"",n,0);
        return ans;
    }
};