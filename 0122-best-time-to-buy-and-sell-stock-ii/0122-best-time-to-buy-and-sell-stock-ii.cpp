class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = prices[0];
        int mini = prices[0];
        int ans  = 0;
        for(int i = 1;i<prices.size();++i)
        {
            if((maxi-mini>=prices[i])||maxi>=prices[i])
            {
                ans +=maxi-mini;
                maxi = prices[i];
                mini = prices[i];
            }
            else maxi = prices[i];
        }
        return ans+maxi-mini;
    }
};