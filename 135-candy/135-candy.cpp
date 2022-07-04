class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        if(n==1)
            return 1;
        map<int,vector<int>>mp;
        for(int i=0;i<rating.size();i++){
            mp[rating[i]].push_back(i);
        }
        vector<int>ans(n,0);
        for(auto it:mp){
            int rate=it.first;
            for(auto it1:it.second){
                if(it1==0){
                    if(rate<=rating[it1+1])
                        ans[it1]=1;
                    else{
                        ans[it1]=ans[it1+1]+1;
                    }
                    continue;
                }
                else if(it1==n-1){
                    if(rate<=rating[it1-1])
                        ans[it1]=1;
                    else{
                        ans[it1]=ans[it1-1]+1;
                    }
                    continue;
                }
                 else if(rate>rating[it1-1] and rate>rating[it1+1])
                        ans[it1]=max(ans[it1+1]+1,ans[it1-1]+1);
                 else if(rate>rating[it1+1])
                        ans[it1]=ans[it1+1]+1;
                else if(rate>rating[it1-1])
                        ans[it1]=ans[it1-1]+1;
                else{
                    ans[it1]=1;
                }
            }
        }
        for(auto it:ans)
            cout<<it<<" "<<endl;
        return accumulate(ans.begin(),ans.end(),0);
    }
};