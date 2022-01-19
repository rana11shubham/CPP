class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_pro[n];
        int max_pro[n];
        int mn=0,pv=prices[0];
        for(int i=1;i<n;i++){
            int p=prices[i];
            if(p>=pv){
                mn=max(mn,abs(p-pv));
            }
            else{
                pv=p;
            }
        }
        
        return mn;
    }

};

