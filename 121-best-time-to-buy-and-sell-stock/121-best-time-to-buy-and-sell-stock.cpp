class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stock=0;
        int cur_price=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            stock=max(stock,prices[i]-cur_price);
            cur_price=min(cur_price,prices[i]);
        }
        return stock;
    }
};