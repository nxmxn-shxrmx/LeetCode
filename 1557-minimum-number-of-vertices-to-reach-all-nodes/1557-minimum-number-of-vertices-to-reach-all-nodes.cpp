class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int>s;
        for(int i = 0;i<n;++i)
            s.insert(i);
        
        for(auto c:edges)
        {
            if(s.find(c[1])!=s.end())
                s.erase(c[1]);
        }
        vector<int>v(s.begin(),s.end());
        return v;
    }
};