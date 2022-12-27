class Solution {
public:
    
    int find(int i,vector<int>&m,vector<int>&si)
    {
        if(m[i]==0)
        {
            si[i]=1;
            return m[i]=i;
        }
        if(m[i]==i)
            return i;
        return m[i]=find(m[i],m,si);
    }
    void make(int a,int b,vector<int>&m,vector<int>&si)
    {
        int u = find(a,m,si);
        int v = find(b,m,si);
        
        if(u==v)
            return;
        if(si[v]>si[u])
            swap(u,v);
        m[v]=u;
        si[u]+=si[v];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>am(n+1),as(n+1),bm(n+1),bs(n+1);
        sort(edges.rbegin(),edges.rend());
        int p = 0;
        for(auto c:edges)
        {
            
            if(c[0]==3)
            {
                int au = find(c[1],am,as);
                int av = find(c[2],am,as);
                
                int bu = find(c[1],bm,bs);
                int bv = find(c[2],bm,bs);
    
                if(au==av)
                    p++;
                else
                {
                    make(c[1],c[2],am,as);
                    make(c[1],c[2],bm,bs);
                }
            }
            else if(c[0]==2)
            {
                   
                int bu = find(c[1],bm,bs);
                int bv = find(c[2],bm,bs);
                
                if(bu==bv)
                    p++;
                else
                    make(c[1],c[2],bm,bs);
            }
            else
            {
                                   
                int bu = find(c[1],am,as);
                int bv = find(c[2],am,as);
                
                if(bu==bv)
                    p++;
                else
                    make(c[1],c[2],am,as);
            }
        }
        
        int u = find(1,am,as);
        int v = find(1,bm,bs);
      
        if(as[u]!=n || bs[v]!=n)
            return -1;
        return p;
    }
};