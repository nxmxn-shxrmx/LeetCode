class Solution {
public:
    vector<int> findBall(vector<vector<int>>& g) {
    int n= g[0].size();
    vector<int>v(n);
    for(int i = 0;i<n;++i)
    {
        if(g[0][i]==1)
        {
            if(i+1<n && g[0][i+1]==1)
                v[i]=i+1;
            else
                v[i]=-1;
                
        }
        else
        {
            if(i-1>=0 && g[0][i-1]==-1)
                v[i]=i-1;
            else
                v[i]=-1;
        }
    }
    
    for(int i = 1;i<g.size();++i)
    {
        for(int j = 0;j<n;++j)
        {
            
            if(v[j]==-1)
                continue;
            
              if(g[i][v[j]]==1)
        {
            if(v[j]+1<n && g[i][v[j]+1]==1)
                v[j]=v[j]+1;
            else
                v[j]=-1;
                
        }
        else
        {
            if(v[j]-1>=0 && g[i][v[j]-1]==-1)
                v[j]=v[j]-1;
            else
                v[j]=-1;
        }
            
        }
        
         
    }
        return v;
    }
};