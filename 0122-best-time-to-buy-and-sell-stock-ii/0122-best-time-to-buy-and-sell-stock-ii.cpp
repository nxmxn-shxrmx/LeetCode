class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int max_profit = 0;
        int cur_max_profit = 0;
        for(auto c:prices)
        {
            if(buy>=c)
            {
                max_profit += cur_max_profit;
                cur_max_profit = 0;
                buy = c;
            }
            else
                
            {
                if((c-buy)>cur_max_profit)
                    cur_max_profit = c-buy;
                else
                {
                    max_profit += cur_max_profit;
                    cur_max_profit = 0;
                    buy=c;
                }
            }
            
        }
        return max_profit+cur_max_profit;
    }
};