class Solution {
public:
    unordered_map<string,set<string>>mp;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n=products.size();
        for(auto it:products){
            string word=it;
            for(int i=1;i<=word.size();i++){
                mp[word.substr(0,i)].insert(word);
            }
        }
        vector<vector<string>>ans;
        for(int i=1;i<=searchWord.size();i++){
            string temp=searchWord.substr(0,i);
            auto result=mp[temp];
            int k=1;
            vector<string>cur_res;
            for(auto it:result){
                if(k>3)
                    break;
                cur_res.push_back(it);
                k++;
            }
            ans.push_back(cur_res);
        }
        return ans;
    }
};