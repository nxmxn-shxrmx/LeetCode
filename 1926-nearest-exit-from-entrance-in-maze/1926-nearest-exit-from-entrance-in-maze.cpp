class Solution {
public:
    int nearestExit(vector<vector<char>>& g, vector<int>& e) {
       
        queue<pair<int,int>>q;
        q.push({e[0],e[1]});
        int st =1;
        g[e[0]][e[1]]='+';
        int d[4][2] = {{0,1},{-1,0},{1,0},{0,-1}};
        
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();
                for(auto c:d)
                {
                    int ni =i+c[0];
                    int nj = j+c[1];
                    if(ni<0 || nj<0 || ni>=g.size() ||nj>=g[0].size() || g[ni][nj]=='+')
                        continue;
                    if(ni==g.size()-1 || nj==g[0].size()-1 || nj==0 || ni==0)
                        return st;
                    g[ni][nj]='+';
                    q.push({ni,nj});
                }
            }
            st++;
        }
        return -1;
    }
};