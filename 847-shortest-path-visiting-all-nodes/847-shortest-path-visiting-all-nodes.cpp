class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        int r = (1<<n);
        int dp[r+1][n+1];
        memset(dp,-1,sizeof(dp));
        queue<pair<int,int>>q;
        for(int i = 0;i<n;++i)
        {
            dp[(1<<i)][i]=0;
            q.push({1<<i,i});
        }
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                int i = q.front().second;
                int max = q.front().first;
                q.pop();
                if(max==r-1)
                    return dp[max][i];
                
                for(auto c:g[i])
                {
                    int x = max|(1<<c);
                    if(dp[x][c]!=-1)
                        continue;
                    
                    q.push({x,c});
                    dp[x][c] = dp[max][i]+1;
                }
            }
        }
        return 1000l;
    }
};