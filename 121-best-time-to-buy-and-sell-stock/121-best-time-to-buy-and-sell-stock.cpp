class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_pro[n];
        int max_pro[n];
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            min_pro[i]=min(mn,prices[i]);
            mn=min_pro[i];
        }
        mn=INT_MIN;
        for(int i=n-1;i>=0;i--){
            max_pro[i]=max(mn,prices[i]);
            mn=max_pro[i];
        }
        int diff=0;
        for(int i=0;i<n;i++){
            if(max_pro[i]>min_pro[i])
            diff=max(diff,max_pro[i]-min_pro[i]);
        }
        return diff;
    }

};

