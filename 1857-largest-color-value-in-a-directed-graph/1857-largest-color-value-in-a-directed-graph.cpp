class Solution {
public:
    int largestPathValue(string co, vector<vector<int>>& edges) {
        vector<vector<int>>g(co.size());
        vector<int>h(co.size());
        for(auto c:edges)
        {
            g[c[0]].push_back(c[1]);
            h[c[1]]++;
        }
        queue<int>q;
        for(int i = 0;i<co.size();++i)
            if(!h[i])q.push(i);
        vector<vector<int>>dp(co.size(),vector<int>(26));
        int u = 0;
        stack<int>s;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            s.push(i);
            for(auto c:g[i])
            {
                h[c]--;
                if(h[c]==0)q.push(c);
            }
        }
        if(s.size()!=co.size())
            return -1;
        
        while(!s.empty())
        {
            int i= s.top();
            s.pop();
            for(auto c:g[i])
            {
                for(int j = 0;j<26;++j)
                    dp[i][j]= max(dp[c][j],dp[i][j]),u=max(u,dp[i][j]);
                
            }
            dp[i][co[i]-'a']++;
            u =max(u,dp[i][co[i]-'a']);
        }
        return u;
    }
};