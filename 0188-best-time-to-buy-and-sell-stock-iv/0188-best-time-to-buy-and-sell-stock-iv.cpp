class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
       vector<vector<int>>pre(2,vector<int>(k+1,0));
       vector<vector<int>>cur(2,vector<int>(k+1,0));
        
        for(int i = prices.size()-1;~i;--i)
        {
            for(int j = k-1;~j;--j)
            {
                cur[1][j]=max(pre[0][j]-prices[i],pre[1][j]);
                cur[0][j]=max(pre[1][j+1]+prices[i],pre[0][j]);
            }
            pre= cur;
        }
        return cur[1][0];
    }
};