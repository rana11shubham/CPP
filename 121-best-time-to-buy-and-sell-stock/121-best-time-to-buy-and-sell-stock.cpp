class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cur_money=prices[0];
        int final_profit=0;
        for(int i=1;i<n;i++){
            if(cur_money<=prices[i]){
                final_profit=max(final_profit,abs(cur_money-prices[i]));
            }
            else{
                cur_money=min(cur_money,prices[i]);
            }
        }
        return final_profit;
    }
};