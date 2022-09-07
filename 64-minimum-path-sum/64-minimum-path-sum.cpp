class Solution {
public:

    int minPathSum(vector<vector<int>>& g) {
        
        int dp[g.size()][g[0].size()];
        memset(dp,0,sizeof(dp));
        dp[0][0]=g[0][0];
        for(int i =1;i<g.size();++i)
            dp[i][0]+=dp[i-1][0]+g[i][0];
        
        for(int j =1;j<g[0].size();++j)
            dp[0][j]+=dp[0][j-1]+g[0][j];
        
        for(int i=1;i<g.size();++i)
        {
            for(int j =1;j<g[0].size();++j)
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j])+g[i][j];   
       }
 
        return dp[g.size()-1][g[0].size()-1];   
    }
};