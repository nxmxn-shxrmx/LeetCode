class Solution {
public:
    int d[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
     queue<pair<int,int>>q,q1;
    int c = INT_MAX;
    void dfs(int i ,int j,vector<vector<int>>&g)
    {
        if(i<0 || j<0 || i>=g.size() || j>=g.size() || g[i][j]!=1)
            return;
        
        g[i][j]=2;
           q.push({i,j});
        for(auto c:d)
            dfs(i+c[0],j+c[1],g);
    }
    int shortestBridge(vector<vector<int>>& g) {
    
        bool t =1; 
        for(int i = 0;i<g.size();++i)
        {
            if(!t)
                break;
            
            for(int j = 0;j<g.size();++j)
            {
                if(g[i][j]==1)
                {
                    
                        dfs(i,j,g);
                        t = false;  
                    break;
                }
                
            }
        }
        
        // for(auto c:g)
        // {
        //     for(auto x:c)
        //         cout<<x<<" ";
        //     cout<<"\n";
        // }
        int st = 0;
        while(!q.empty())
        {
            
            while(!q.empty())
            {
                int i = q.front().first;
                int j = q.front().second;
            
                q.pop();
                
                for(auto c:d)
                {
                    int ni = i+c[0];
                    int nj = j+c[1];
                    if(ni<0 || nj<0 || ni>=g.size() || nj>=g.size() || g[ni][nj]==2)
                    continue;
            
                    else if(g[ni][nj]==1)
                        return st;

                    
                    g[ni][nj]=2;
                    q1.push({ni ,nj});  
        
                }
            }
            
            st++;
            swap(q1,q);
        }
            
        return st;
        
    }
};