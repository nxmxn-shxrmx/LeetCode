class Solution {
public:
    map<int,int>par;
    map<int,int>siz;
    int find(int x)
    {
        if(par[x]==x)
            return x;
        return par[x]=find(par[x]);
    }
    void make(int i,int j,vector<vector<int>>&g)
    {
        int n = g[0].size();
        int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        if(par.find(i*n+j+1)==par.end())
            par[i*n+j+1]=i*n+j+1,siz[i*n+j+1]=1;
        
        for(auto c:d)
        {
            if(i+c[0]>=0 && i+c[0]<g.size() && j+c[1]>=0 && j+c[1]<g[0].size() && g[i+c[0]][j+c[1]]==1)
            {
                 if(par.find((i+c[0])*n+(j+c[1])+1)==par.end())
                    par[(i+c[0])*n+(j+c[1])+1]=(i+c[0])*n+(j+c[1]+1),siz[(i+c[0])*n+(j+c[1])+1]=1;  
                int u = find(i*n+j+1);
                int v = find((i+c[0])*n+(j+c[1])+1);
                if(u==v)
                    continue;
                
                    if(siz[u]<siz[v])
                        swap(u,v);
                    if(v==0)
                        swap(u,v);
                    par[v]=u;
                    siz[u]+=siz[v];
                
            }
        }
            if(i==0)
            {
                int u = find(j+1);
                if(u!=0)
                siz[0]+=siz[u],par[u]=0;
            }
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        par[0]=0;
        siz[0]=0;
        for(auto c:hits)
            if(grid[c[0]][c[1]]==1)grid[c[0]][c[1]]=2;
        
        for(int i = 0;i<grid.size();++i)
        {
            for(int j = 0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                    make(i,j,grid);
                
            }
        }
        int y = siz[0];
        vector<int>v(hits.size());
        for(int i = hits.size()-1;~i;--i)
        {
            if(grid[hits[i][0]][hits[i][1]]!=2)
                continue;
           
            grid[hits[i][0]][hits[i][1]]=1;
            make(hits[i][0],hits[i][1],grid);
            int x = siz[0];
       //     cout<<x<<" "<<y<<"\n";
            v[i]=max(x-y-1,0);
            y=x;
        }
    
     
        return v;
        
    }
};