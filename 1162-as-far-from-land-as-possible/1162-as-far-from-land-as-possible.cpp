class Solution {
public:
   
    int maxDistance(vector<vector<int>>& g) {
        
        int d[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
        queue<pair<int,int>>q;
        for(int i = 0;i<g.size();++i)
        {
            for(int j = 0;j<g[0].size();++j)
            {
                if(g[i][j]==1)
                    for(auto c:d)
                        q.push({i+c[0],j+c[1]});
            }
        }
        int st =0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int i = q.front().first;
                int j = q.front().second;
                
                q.pop();
                
                if(i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j]==1)
                    continue;
                
                g[i][j]=1;
                for(auto c:d)
                    q.push({i+c[0],j+c[1]});
                
            }
            st++;
        }
       
        return st<=1?-1:st-1;
    }
};