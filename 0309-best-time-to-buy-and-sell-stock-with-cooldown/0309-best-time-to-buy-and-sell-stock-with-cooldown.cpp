class Solution {
public:
    int dp[5001][2];
    int f(int i,int b,vector<int>&v)
    {
        if(i>=v.size())
            return 0;
        if(dp[i][b]!=-1)
            return dp[i][b];
        if(b)
            return dp[i][b]= max(f(i+1,0,v)-v[i],f(i+1,b,v));
        return dp[i][b]= max(f(i+2,1,v)+v[i],f(i+1,b,v));
    }
    int maxProfit(vector<int>& prices) {
        vector<int>pre(2,0);
        vector<int>cur(2,0);
        vector<int>fut(2,0);
        for(int i = prices.size()-1;~i;--i)
        {
            fut[1]=max(cur[0]-prices[i],cur[1]);
            fut[0]=max(pre[1]+prices[i],cur[0]);
            
            pre = cur;
            cur = fut;
        
        }
        return fut[1];
    }
};