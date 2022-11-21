class Solution {
public:
    int nearestExit(vector<vector<char>>& g, vector<int>& e) {
        queue<pair<int,int>>q;
          map<pair<int,int>,bool>b;
        b[{e[0],e[1]}]=1;
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto c:d)
        {
            int x = c[0]+e[0];
            int y = c[1]+e[1];
            if(x>=0 && y>=0 && x<g.size() && y<g[0].size() && g[x][y]=='.')
                q.push({x,y}),b[{x,y}]=1;
        }
        int s=1;
        while(!q.empty())
        {
            int z = q.size();
            while(z--)
            {
                int u = q.front().first;
                int v = q.front().second;
                if(u==0 || v==0 || v==g[0].size()-1 || u==g.size()-1)
                    return s;
                q.pop();
                for(auto c:d)
                {
                     int x = c[0]+u;
            int y = c[1]+v;
            if(x>=0 && y>=0 && x<g.size() && y<g[0].size() && g[x][y]=='.' && !b[{x,y}])
                q.push({x,y}),b[{x,y}]=1;
                }
                
            }
            s++;
        }
        return -1;
    }
};