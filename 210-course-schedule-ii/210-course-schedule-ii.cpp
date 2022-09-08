class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>v(n);
        vector<int>ind(n);
        for(int i =0;i<p.size();++i)
        {
            ind[p[i][0]]++;
            v[p[i][1]].push_back(p[i][0]);
        }
        queue<int>q;
        for(int i =0;i<n;++i)
        {
            if(ind[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int i=q.front();
            ans.push_back(i);
            for(auto c:v[i])
            {
                ind[c]--;
                if(ind[c]==0)
                    q.push(c);
            }
            q.pop();
        }
        if(ans.size()==n)
            return ans;
        return {};
    }
    
};