class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<set<int>>v(n);
        if(n==1)
            return {0};
        if(n==2)
            return {0,1};
        
        for(auto c:edges)
        {
            v[c[0]].insert(c[1]);
            v[c[1]].insert(c[0]);
        }
        vector<int>l;
        for(int i = 0;i<n;++i)
        {
            if(v[i].size()==1)
                l.push_back(i);
        }
       
        while(n>2)
        {
            n-=l.size();
            vector<int>g;
            for(auto c:l)
            {
                int i = *v[c].begin();
                v[i].erase(c);
                if(v[i].size()==1)
                    g.push_back(i);
            }
            swap(l,g);
        }
        return l;
    }
};