class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        
        priority_queue<pair<int,int>>q;
        for(auto c:p)
            q.push({c[0],-c[1]});
        
        vector<vector<int>>v(p.size());
        
        while(!q.empty())
        {
            int h = q.top().first;
            int k = -q.top().second;
            int g = k;
            while(v[g].size()!=0)
            {
                swap(h,v[g][0]);
                swap(k,v[g][1]);
                g++;
            }
            v[g].push_back(h);
            v[g].push_back(k);
            q.pop();
        }
        return v;
    }
};