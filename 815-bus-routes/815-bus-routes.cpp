class Solution {
public:
    unordered_set<int>p;
    unordered_map<int,unordered_set<int>>m;

    int numBusesToDestination(vector<vector<int>>& g, int s, int t) {
        
        if(s==t)
            return 0;
        for(int i = 0;i<g.size();++i)
        {
            for(auto c:g[i])
                m[c].insert(i);
        }
    
        queue<pair<int,int>>q;
        q.push({s,0});
        p.insert(s);
        while(!q.empty())
        {
            auto it = q.front();
            if(it.first==t)
                return it.second;
            q.pop();
            for(auto c:m[it.first])
            {
                for(auto x:g[c])
                {
                    if(p.find(x)==p.end())
                    {
                        q.push({x,it.second+1});
                        p.insert(x);
                    }
                }
                g[c].clear();
            }
        }
        return -1;
    }
};