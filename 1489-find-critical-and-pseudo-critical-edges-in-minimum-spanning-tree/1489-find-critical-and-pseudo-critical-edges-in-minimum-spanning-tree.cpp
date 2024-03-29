class Solution {
public:
    int par(int i,vector<int>&v)
    {
        if(v[i]==-1)return v[i]=i;
        if(v[i]==i)return i;
        
        return v[i] = par(v[i],v);
    }
    
    int findMST(int n,int k,int b,vector<vector<int>>&edges)
    {
        int sum = 0;
        vector<int>v(n,-1);
        vector<int>siz(n,1);
        
        if(b)
        {
            vector<int>c = edges[k];
            int u = par(c[0],v);
            int p = par(c[1],v);
            sum+=c[2];
                v[p]=u;
                siz[u]+=siz[p];
        }
        
        for(int i = 0;i<edges.size();++i)
        {
            
            vector<int>c = edges[i];
            if(i==k)continue;
            int u = par(c[0],v);
            int p = par(c[1],v);
            if(u!=p)
            {
                if(siz[p]>siz[u])swap(p,u);
                sum+=c[2];
                v[p]=u;
                siz[u]+=siz[p];
            }
        }
        int o = siz[par(0,v)];
        if(o!=n)return INT_MAX;
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int sum = 0;
        for(int i = 0;i<edges.size();++i)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
     
        vector<int>v(n,-1);
        vector<int>siz(n,1);
        
        for(int i = 0;i<edges.size();++i)
        {
            vector<int>c = edges[i];
            
            int u = par(c[0],v);
            int p = par(c[1],v);
            if(u!=p)
            {
                if(siz[p]>siz[u])swap(p,u);
                sum+=c[2];
                v[p]=u;
                siz[u]+=siz[p];
            }
        }
        
        vector<vector<int>>ans(2);
        for(int i = 0;i<edges.size();++i)
        {
            int d = findMST(n,i,0,edges);
            if(d>sum)
                ans[0].push_back(edges[i][3]);
            
            else
            {
                d = findMST(n,i,1,edges);
                if(d==sum)ans[1].push_back(edges[i][3]);
            }
        }
        
    
      //  cout<<sum<<"\n";
        return ans;
    }
};