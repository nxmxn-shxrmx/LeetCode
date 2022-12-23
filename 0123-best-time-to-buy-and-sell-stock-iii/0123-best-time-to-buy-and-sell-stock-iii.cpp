class Solution {
public:
    
//     int f(int i,int k,int b,vector<int>&v)
//     {
//         if(i==v.size() || k==2)
//             return 0;
        
//         if(dp[i][b][k]!=-1)
//             return dp[i][b][k];
//         if(b)
//             return dp[i][b][k]=max(f(i+1,k,0,v)-v[i],f(i+1,k,b,v));
        
//         return dp[i][b][k]=max(f(i+1,k+1,1,v)+v[i],f(i+1,k,b,v));
//     }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i = prices.size()-1;~i;--i)
        {
            for(int k = 1;~k;--k)
            {
                dp[i][1][k]=max(dp[i+1][0][k]-prices[i],dp[i+1][1][k]);
                dp[i][0][k]=max(dp[i+1][1][k+1]+prices[i],dp[i+1][0][k]);
            }
        }
        return dp[0][1][0];
    }
};
