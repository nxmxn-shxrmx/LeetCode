class Solution {
public:
    vector<bool>p;
    void dfs(int i, vector<vector<int>>v)
    {
        for(int j = 0;j<v.size();++j)
        {
            if(v[i][j]==1 && p[j]==0)
            {
                
                p[j]=1;
                dfs(j,v);
            }
        }     
    }
    int findCircleNum(vector<vector<int>>& is) {
       
        p = vector<bool>(is.size(),0);
        int c = 0;
        for(int i =0;i<is.size();++i)
        {
            if(p[i]==0)
            {
                dfs(i,is);
                c++;
            }
        }
        return c;
        
    }
};