class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int>m;
        for(auto it:s){
            m[it-'a']++;
        }
        vector<int>temp;
        for(auto it:m)
            temp.push_back(it.second);
        unordered_map<int,int>mp;
        sort(temp.begin(),temp.end(),greater<int>());
        int count=0;
        for(int i=0;i<temp.size();i++){
           while(mp.find(temp[i])!=mp.end()){
                if(temp[i]==1){
                    count++;
                    break;
                }
               else{
               temp[i]--;
               count++;
               }
           }
            mp[temp[i]]=1;
        }
        return count;
    }
};