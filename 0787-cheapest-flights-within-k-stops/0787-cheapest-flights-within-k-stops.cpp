class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>b(n,INT_MAX);
        vector<vector<pair<int,int>>>v(n);
        for(auto c:flights)
            v[c[0]].push_back({c[1],c[2]});
        
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>q;
        q.push({0,src,0});
        
        b[src]=0;
        int ans = INT_MAX;
        while(!q.empty())
        {
                int a =  q.top()[2];
                int u = q.top()[1];
                int p = q.top()[0];
                q.pop();
        
                if(p>k)
                    continue;
    
                for(auto c:v[u])
                {
                    if(b[c.first]>a+c.second)
                    {
                        b[c.first]=a+c.second;
                        q.push({p+1,c.first,a+c.second});
                    }
                }
                
            
        }
        return b[dst]==INT_MAX?-1:b[dst];
    }
};