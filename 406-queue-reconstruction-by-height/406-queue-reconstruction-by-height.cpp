class Solution {
public:
    static bool comp(pair<int,int>p1,pair<int,int>p2){
        if(p1.first>p2.first)
            return true;
        else if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<pair<int,int>>vc;
        for(auto it:people){
            vc.push_back({it[0],it[1]});
        }
        sort(vc.begin(),vc.end(),comp);
        vector<pair<int,int>>ans;
        for(auto it:vc){
            int pos=it.second;
            ans.insert(ans.begin() + it.second, it);
        }
        vector<vector<int>>result;
        for(auto it:ans){
            vector<int>temp;
            temp.push_back(it.first);
            temp.push_back(it.second);
            result.push_back(temp);
        }
        return result;
    }
};