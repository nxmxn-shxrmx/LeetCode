class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int max_profit = 0;
        int cur_max_profit = 0;
        for(auto c:prices)
        {
            if(buy>=c || (c-buy)<=cur_max_profit)
            {
                max_profit += cur_max_profit;
                cur_max_profit = 0;
                buy = c;
            }
            else
                cur_max_profit = c-buy;
            
        }
        return max_profit+cur_max_profit;
    }
};