class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>v(n+1);
        for(auto c:roads)
        {
            v[c[0]].push_back({c[1],c[2]});
            v[c[1]].push_back({c[0],c[2]});
        }
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>>q;
        q.push({INT_MAX,1});
        dis[1]=INT_MAX;
        while(!q.empty())
        {
            int p = abs(q.top().first);
            int i = q.top().second;
            q.pop();
            for(auto c:v[i])
            {
                if(dis[c.first]>(min(p,c.second)))
                {
                    dis[c.first] = min(p,c.second);
                    q.push({-dis[c.first],c.first});
                }
            }
        }
    
     
        return dis[n];
    }
};