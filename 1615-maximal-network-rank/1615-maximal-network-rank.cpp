class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       int h = INT_MIN;
        vector<vector<int>>v(n);
        map<pair<int,int>,int>m;
        for(auto c:roads)
        {
            v[c[0]].push_back(c[1]);
            v[c[1]].push_back(c[0]);
            m[{c[0],c[1]}]=1;
            m[{c[1],c[0]}]=1;
        }
        for(int i = 0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int p = v[i].size()+v[j].size();
                if(m[{i,j}]==1)
                    p--;
                h = max(h,p);
            }
        }
        return h;
    }
};