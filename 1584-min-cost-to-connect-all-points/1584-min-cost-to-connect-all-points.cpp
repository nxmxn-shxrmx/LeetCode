class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        
        vector<vector<long long>>v(p.size(),vector<long long>(p.size()));
        
        for(int i = 0;i<p.size();++i)
        {
            for(int j=i+1;j<p.size();++j)
            {
                if(i==j)
                    continue;
                
                v[i][j]=abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                v[j][i]=abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                
            }
        }
        priority_queue<pair<int,int>>q;
        vector<bool>vis(p.size());
        vector<long long>k(p.size(),INT_MAX);
        k[0]=0;
        q.push({0,0});
        while(!q.empty())
        {
            int i =q.top().second;
            q.pop();
            int p =-1*q.top().first;
            vis[i]=true;
            
            for(int j=0;j<vis.size();++j)
            {
                if(!vis[j] && v[i][j]<k[j])
                {
                    k[j]=v[i][j];
                    q.push({-v[i][j],j});
                }
            }
        }
        long long u =0;
        for(auto c:k)
            u+=c;
        
        
        return u;
    }
};