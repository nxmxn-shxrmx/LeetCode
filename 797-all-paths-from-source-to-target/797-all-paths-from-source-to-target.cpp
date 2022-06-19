class Solution {
public:
    vector<vector<int>>v;
    void dfs(int i,vector<int>&f,vector<vector<int>>g)
    {
        if(i==g.size()-1)
        {    
            f.push_back(i);
            v.push_back(f);
            f.pop_back();
            return;
        }
        f.push_back(i);
        for(auto c:g[i])
        {
            dfs(c,f,g);
        }
        f.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<int>f;
        dfs(0,f,g);
        return v;
    }
};