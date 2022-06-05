class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=prices[0];
        int profit=0;
        for(int i:prices){
            if(i<min_price){
                min_price=min(min_price,i);
                continue;
            }
            profit=max(profit,abs(min_price-i));
            min_price=min(min_price,i);
        }
        return profit;
    }
};