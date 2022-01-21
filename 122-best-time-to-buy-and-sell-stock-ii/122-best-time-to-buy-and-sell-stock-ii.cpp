class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int money_without_stock=0,money_with_stock=-100000;
        int n=prices.size();
        for(int it:prices){
            money_with_stock=max(money_with_stock,money_without_stock-it);
            money_without_stock=max(money_without_stock,money_with_stock+it);
            
            }
        return money_without_stock;
    }
};