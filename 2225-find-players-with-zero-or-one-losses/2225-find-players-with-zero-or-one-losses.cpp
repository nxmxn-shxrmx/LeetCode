class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       unordered_map<int,int>m;
        for(auto c:matches)
        {
            if(m[c[0]]==0)
                m[c[0]]=0;
            m[c[1]]++;
        }
        vector<set<int>>v(2);
        for(auto c:m)
        {
            if(c.second==0)
                v[0].insert(c.first);
            if(c.second==1)
                v[1].insert(c.first);
        }
        vector<int>a(v[0].begin(),v[0].end());
        vector<int>b(v[1].begin(),v[1].end());
        
        return {a,b};
    }
};