class Solution {
public:
  
    vector<int> sortItems(int n, int o, vector<int>& g, vector<vector<int>>& b) {
        map<int,set<int>>m;
        map<int,set<int>>gr;
        map<int,set<int>>h;
        map<int,int>ing,inti;
        int c = o;
        for(int i = 0;i<g.size();++i)
        {
            if(g[i]==-1)
                g[i]=c++;
            
            h[g[i]].insert(i);
        }
        for(int i = 0;i<n;++i)
        {
            for(auto c:b[i])
            {
                if(g[c]==g[i])
                {
                    if(gr[c].find(i)==gr[c].end())
                        inti[i]++;
                    gr[c].insert(i);
                  
                }
                else
                {
                    if(m[g[c]].find(g[i])==m[g[c]].end())
                        ing[g[i]]++;
                m[g[c]].insert(g[i]);
                }
            }
        }
        queue<int>q;
        vector<int>p,v;
        for(int i = 0;i<c;++i)
        {
            if(ing[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            p.push_back(q.front());
            
            
            for(auto x:m[q.front()])
            {
                ing[x]--;
                if(ing[x]==0)
                    q.push(x);
            }
            q.pop();
        }
  
     if(p.size()!=c)
        return v;
         
        
        for(auto c:p)
        {
         
        
            for(auto x:h[c])
                if(inti[x]==0)
                    q.push(x);
            int j = h[c].size();
            while(!q.empty())
            {
                v.push_back(q.front());
                j--;
                for(auto c:gr[q.front()])
                {
                    inti[c]--;
                    if(inti[c]==0)
                        q.push(c);
                        
                }
                q.pop();
            }
            
            if(j!=0)
                return {};
        }
        return v;
    }
};