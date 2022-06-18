class Solution {
public:
    int d[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    int c = INT_MAX;
    void dfs(int i ,int j,vector<vector<int>>&g)
    {
        if(i<0 || j<0 || i>=g.size() || j>=g.size() || g[i][j]!=1)
            return;
        
        g[i][j]=2;
        for(auto c:d)
            dfs(i+c[0],j+c[1],g);
    }
    int shortestBridge(vector<vector<int>>& g) {
        
        queue<pair<pair<int,int>,int>>q;
        bool t =1; 
        for(int i = 0;i<g.size();++i)
        {
            for(int j = 0;j<g.size();++j)
            {
                if(g[i][j]==1)
                {
                    if(t)
                    {
                        dfs(i,j,g);
                        t = false;
                        
                    }
                    else
                    {
                        for(auto c:d)
                            q.push({{c[0]+i,j+c[1]},0});
                    }
                }
                
            }
        }
        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            
            int k = q.front().second;
            
            q.pop();
            if(i<0 || j<0 || i>=g.size() || j>=g.size() || g[i][j]==1)
                continue;
            
            if(g[i][j]==2)
            {
                if(c>k)
                    c= k;
            }
            else 
            {
                g[i][j]=1;
                for(auto c:d)
                            q.push({{c[0]+i ,j+c[1]},k+1});   
            }
        }
            
            return c;
        
    }
};