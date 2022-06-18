class WordFilter {
public:
    unordered_map<string,int>mp;
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            string temp=words[i];
            int sze=temp.size();
            for(int j=1;j<=sze;j++){
                string prefix=temp.substr(0,j);
                for(int k=0;k<sze;k++){
                    string suffix=temp.substr(k,sze);
                    mp[prefix+"#"+suffix]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string temp=prefix+"#"+suffix;
        return mp[temp]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */