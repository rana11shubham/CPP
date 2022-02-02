class Solution {
public:
    unordered_map<int,string>mp;
    vector<string>ans;
    void solve(string digit,int pos,int n,string temp){
        if(pos==n){
            ans.push_back(temp);
            return;
        }
        string letter=mp[digit[pos]-'0'];
        for(int i=0;i<letter.size();i++){
               solve(digit,pos+1,n,temp+letter[i]);
            }
        
    }
    vector<string> letterCombinations(string digits) {
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        int n=digits.length();
        if(n==0)
            return {};
        solve(digits,0,n,"");
        return ans;
    }
};