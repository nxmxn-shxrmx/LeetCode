class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n=g.size();
        int co = (1<<n);
        int dp[co][n];
        memset(dp,-1,sizeof(dp));
        queue<vector<int>>q;
        for(int i = 0;i<g.size();++i)
        {
            q.push({1<<i,i});
            dp[1<<i][i]=0;
        }
        
        while(!q.empty())
        {
            int x =q.front()[0];
            int i = q.front()[1];
            q.pop();
           
            if(x==(co-1))return dp[x][i];
            for(auto c:g[i])
            {
                if(dp[x|(1<<c)][c]!=-1)continue;
                
                dp[x|(1<<c)][c]=dp[x][i]+1;
                q.push({x|(1<<c),c});
            }
        }
        return 0;
    }
};

