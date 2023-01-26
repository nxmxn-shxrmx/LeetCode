class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        priority_queue<vector<int>>q;
        q.push({0,0,src});
        dist[src]=0;
        vector<vector<pair<int,int>>>g(n);
        for(auto c:flights)
            g[c[0]].push_back({c[1],c[2]});
        while(!q.empty())
        {
            int i = q.top()[2];
            int u = abs(q.top()[0]);
            int pr =abs(q.top()[1]);
            q.pop();
            if(u>k)continue;
            for(auto c:g[i])
            {
                if(dist[c.first]>(pr+c.second))
                    q.push({-(u+1),-(pr+c.second),c.first}),dist[c.first]=pr+c.second;
            }
            
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};