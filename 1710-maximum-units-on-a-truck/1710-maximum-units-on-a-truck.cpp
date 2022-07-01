class Solution {
public:
    static bool comp(pair<int,int>a,pair<int,int>b){
        if(a.first>b.first)
            return true;
        else if(a.first==b.first)
            return a.second<b.second;
        else return false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>>vc;
        for(auto it:boxTypes)
            vc.push_back({it[1],it[0]});
        sort(vc.begin(),vc.end(),comp);
        for(auto it:vc)
            cout<<it.first<<" "<<it.second<<endl;
        int ans=0;
        int cnt=0;
        for(auto it:vc){
            cnt+=it.second;
            if(cnt<=truckSize){
                ans+=(it.first)*(it.second);
            }
            else{
                cnt-=it.second;
                cnt=truckSize-cnt;
                ans+=cnt*it.first;
                break;
            }
        }
        return ans;
    }
};