class Solution {
public:
    map<int,int>m;
    
    int find(int v)
    {
        if(m[v]==v)
            return v;
        return m[v]=find(m[v]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& ed) {
        
        vector<int>v(ed.size()+1,-1);
        vector<int>an,a2;
        int u =-1;
        int y =-1;
        for(int i =0;i<ed.size();++i)
        {
            if(v[ed[i][1]]!=-1)
            {
                u = i;
                y = v[ed[i][1]];
                continue;
            }
            v[ed[i][1]]=i;
        }
      
        for(int i =0;i<ed.size();++i)
        {
            if(u==i)
                continue;
            if(m[ed[i][0]]==0)
                m[ed[i][0]]=ed[i][0];
            int p = find(ed[i][0]);
            if(m[ed[i][1]]==0)
                m[ed[i][1]] = ed[i][1];
            int q = find(ed[i][1]);
            if(p==q)
            {
                if(y==-1)
                    y = i;
                return ed[y];
            }
            m[q]=p;
        }
        return ed[u];
        
    }
};