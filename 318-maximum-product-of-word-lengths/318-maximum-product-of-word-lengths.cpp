class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=words.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            for(auto it:words[i])
                mp[it]++;
            for(int j=i+1;j<n;j++){
                int flag=0;
                for(auto x:words[j]){
                    if(mp[x]){
                        flag=1;
                        break;
                    }
                }
                    if(flag)
                        continue;
                    else{
                    int len=words[i].length()*words[j].length();
                   // cout<<words[i]<<" "<<words[j]<<endl;
                    ans=max(ans,len);
                }
            }
            mp.clear();
        }
        return ans;
    }
};