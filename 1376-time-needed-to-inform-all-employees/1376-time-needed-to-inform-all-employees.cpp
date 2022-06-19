class Solution {
public:
    int dfs(int i,vector<vector<int>>&v,vector<int>&in)
    {
        int dt = 0;
        for(auto c:v[i])
        {
           dt=max(dfs(c,v,in),dt);
        }
        return dt+in[i];
    }
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& in) {
        vector<vector<int>>v(n);
    
        
        for(int i = 0;i<n;++i)
        {
            if(m[i]==-1)
                continue;
            v[m[i]].push_back(i);
        }
       return  dfs(h,v,in);
    }
};