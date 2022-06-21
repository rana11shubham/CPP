class Solution {
public:
    unordered_map<char,int>mp;
    string reorganizeString(string str) {
        string result="";
        char prev='#';
        for(auto it:str)
            mp[it]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
            pq.push({it.second,it.first});
        while(pq.size()>1){
            auto ele1=pq.top();
            pq.pop();
            auto ele2=pq.top();
            pq.pop();
            result+=ele1.second;
            result+=ele2.second;
            ele1.first--;
            ele2.first--;
            if(ele1.first>0)
                pq.push(ele1);
            if(ele2.first>0)
                pq.push(ele2);
        }
        if(pq.size()==1){
            auto it=pq.top();
            if(it.first>1){
                return "";
            }
            else result+=it.second;
        }
        return result;
    }
};