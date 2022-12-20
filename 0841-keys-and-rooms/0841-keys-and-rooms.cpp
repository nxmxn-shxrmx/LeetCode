class Solution {
public:
    int c = 0;
    vector<bool>v;
    void dfs(int i,vector<vector<int>>&r)
    {
        if(v[i]==true)
            return;
        
        c++;
        v[i]=true;
        for(auto c:r[i])
        {
            if(!v[c])
                dfs(c,r);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& r) {
    
        v = vector<bool>(r.size());
        dfs(0,r);
        return (c==r.size());
    }
};