class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
       int buy1=-1000000;
        int sell1=0;
        int buy2=sell1-prices[0];
        int sell2=0;
        for(auto it:prices){
            buy1=max(buy1,-it);
            sell1=max(sell1,buy1+it);
            buy2=max(buy2,sell1-it);
            sell2=max(sell2,buy2+it);
        }
    return max(sell1,sell2);
    }
};
