class Solution {
public:
    map<pair<int,int>,pair<int,int>>m;
    map<pair<int,int>,int>size;
    
    pair<int,int>par(int i,int j)
    {
        pair<int,int>p={i,j};
        if(m[{i,j}]==p)
            return {i,j};
        return m[{i,j}]=par(m[{i,j}].first,m[{i,j}].second);
    }
    int removeStones(vector<vector<int>>& st) {
        
        for(auto c:st)
        {
            m[{c[0],c[1]}]={c[0],c[1]};
            size[{c[0],c[1]}]=1;
            for(auto x:m)
            {
                if(x.first.first==c[0] || x.first.second==c[1])
                {
                    auto u = par(c[0],c[1]);
                    auto v = par(x.first.first,x.first.second);
                    if(u!=v)
                    {
                        if(size[u]<size[v])
                            swap(u,v);
                        size[u]+=size[v];
                        m[v]=u;
                    }
                }
            }
            
        }
        map<pair<int,int>,bool>b;
        int h = 0;
        for(auto c:m)
        {
            auto u = par(c.first.first,c.first.second);
            if(!b[u])
            {
                b[u]=1;
                h+=size[u]-1;
                
            }
        }
        return h;
    }
};