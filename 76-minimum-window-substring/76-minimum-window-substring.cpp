class Solution {
public:
    string minWindow(string s, string p) {
        int i=0,j=0,ans=INT_MAX;
        unordered_map<char,int>mp;
        string final_ans="";
        int n=s.length();
        for(auto it:p)
            mp[it]++;
        int count=mp.size();
        for(;j<n;j++){
            
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            if(count==0){
                while(i<=j){
                    if(mp.find(s[i])!=mp.end()){
                        if(mp[s[i]]==0){
                            if(ans>(j-i+1)){
                                ans=j-i+1;
                                final_ans=s.substr(i,j-i+1);
                        
                            }
                            break;
                        }
                        else if(mp[s[i]]<0){
                            mp[s[i]]++;
                            i++;
                        }
                    }
                    else{
                        i++;
                    }
                }
            }
            
        }
        return final_ans;
    }
};