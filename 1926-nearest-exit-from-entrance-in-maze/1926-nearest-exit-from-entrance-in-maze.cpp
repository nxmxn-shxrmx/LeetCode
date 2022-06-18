class Solution {
public:
    int nearestExit(vector<vector<char>>& g, vector<int>& e) {
       
        queue<pair<pair<int,int>,int>>q;
        q.push({{e[0],e[1]},0});
        int st =1;
        // for(auto c:g)
        // {
        //     for(auto x:c)
        //         cout<<x<<" ";
        //     cout<<"\n";
        // }
        g[e[0]][e[1]]='+';
        int d[4][2] = {{0,1},{-1,0},{1,0},{0,-1}};
        int cz = INT_MAX;
        
        while(!q.empty())
        {
        
            int i = q.front().first.first;
            int j = q.front().first.second;
            int k = q.front().second;
            q.pop();
            for(auto c:d)
            {
                int ni =i+c[0];
                int nj = j+c[1];
                if(ni<0 || nj<0 || ni>=g.size() ||nj>=g[0].size() || g[ni][nj]=='+')
                        continue;
                if(ni==g.size()-1 || nj==g[0].size()-1 || nj==0 || ni==0)
                {

                    if(k+1<cz)
                        cz  =k+1;
                }
                    g[ni][nj]='+';
                    q.push({{ni,nj},k+1});
                }
        }
        return cz==INT_MAX?-1:cz;
    }
};