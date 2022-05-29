class Solution {
public:
    int uncommon(vector<vector<int>>&mp,int i,int j){
        for(int k=0;k<26;k++){
            if(mp[i][k]==mp[j][k] && mp[i][k]!=0){
                return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=words.size();
        vector<vector<int>>mp(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(auto it:words[i]){
                mp[i][it-'a']=1;
            }
            for(int j=0;j<i;j++){
                if(!uncommon(mp,i,j))
                    continue;
                else{
                    int len=words[i].length()*words[j].length();
                    //cout<<words[i]<<" "<<words[j]<<endl;
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};