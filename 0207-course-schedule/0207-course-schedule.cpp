class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
     
        vector<int>ind(n);
        vector<vector<int>>v(n);
        
        for(auto c:p)
        {
            v[c[1]].push_back(c[0]);
            ind[c[0]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i = 0;i<n;++i)
            if(ind[i]==0)q.push(i),ans.push_back(i);
        if(q.empty())return 0;
        
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            
            for(auto c:v[i])
            {
                ind[c]--;
                if(ind[c]==0)q.push(c),ans.push_back(c);
            }
        }
        return ans.size()==n;
    }
};