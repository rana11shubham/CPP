class Solution {
public:
    unordered_map<string,bool>mp;
    set<string>word;
    void helper(string it,queue<string>&q)
    {
        for(int i=0;i<it.length();i++)
        {
            char c=it[i];
            for(int j=0;j<26;j++){
                char temp=j+'a';
                string temp1=it.substr(0,i)+temp+it.substr(i+1);
                if(word.find(temp1)!=word.end() && !mp[temp1]){
                    q.push(temp1);
                    mp[temp1]=true;
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // First condition would be to check if endWord is present in wordList or not
        // Map contains whether I have travelled to that word or not
        for(auto it:wordList){
            mp[it]=false;
            word.insert(it);
        }
        if(word.find(endWord)==word.end())
            return 0;
        queue<string>q;
        q.push(beginWord);
        int count=1;
        mp[beginWord]=true;
        while(q.empty()!=true){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto it=q.front();
                q.pop();
                if(it==endWord){
                    return count;
                }
                helper(it,q);
            }
            count++;
        }
        return 0;
    }
};