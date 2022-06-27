class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<pair<int,int>>q;
        int t = 0;
        for(int i  =0;i<g.size();++i)
        {
            for(int j = 0;j<g[0].size();++j)
            {
                if(g[i][j]==2)
                    q.push({i,j});
                if(g[i][j]==1)
                    t++;
            }
        }
        
        int d[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
        int st = -1;
        //cout<<t<<"\n";
        if(q.empty()&&t==0)
            return 0;
        
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                int in = q.front().first;
                int jn =q.front().second;
                q.pop();
                for(auto c:d)
                {
                    int i = in+c[0];
                    int j = jn+c[1];
                    if(i<0 || j<0 || i>=g.size()||j>=g[0].size() || g[i][j]==0 || g[i][j]==2)continue;
                
                    q.push({i,j}),t--,g[i][j]=2;
                    
                }
            }
            //cout<<"\n\n";
            st++;
        }
        //cout<<t<<"\n";
        if(t==0)
            return st;
        return -1;
    }
   
};