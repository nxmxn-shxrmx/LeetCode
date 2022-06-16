class Solution {
public:
   
    int maxDistance(vector<vector<int>>& g) {
        queue<pair<int,int>>q,q1;
        for(int i = 0;i<g.size();++i)
        {
            for(int j = 0;j<g[0].size();++j)
            {
                if(g[i][j]==1)
                {
                    q.push({i-1,j});
                    q.push({i,j-1});
                    q.push({i+1,j});
                    q.push({i,j+1});
                }
            }
        }
        int st =  0;
        while(!q.empty())
        {
            st++;
            while(!q.empty())
            {
                auto it = q.front();
                int i = it.first;
                int j = it.second;
                q.pop();
                if(i<0 || j<0 || i>=g.size() || j>=g.size() || g[i][j]==1)
                    continue;
                g[i][j]=1;
                q1.push({i-1,j});
                q1.push({i,j-1});
                q1.push({i+1,j});
                q1.push({i,j+1});
                
            }
            swap(q,q1);
        }
        return st>1?st-1:-1;
       
    }
};