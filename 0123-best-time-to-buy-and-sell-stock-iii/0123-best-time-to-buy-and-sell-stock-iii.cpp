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
        vector<vector<int>>pre(2,vector<int>(3,0));
        vector<vector<int>>cur(2,vector<int>(3,0));
        for(int i = prices.size()-1;~i;--i)
        {
            for(int k = 1;~k;--k)
            {
                cur[1][k]=max(pre[0][k]-prices[i],pre[1][k]);
                cur[0][k]=max(pre[1][k+1]+prices[i],pre[0][k]);
            }
            pre= cur;
        }
        return cur[1][0];
    }
};
