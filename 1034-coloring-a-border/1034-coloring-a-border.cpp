class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& g, int r, int c, int col) {
     
        queue<pair<int,int>>q,q1;
        map<pair<int,int>,bool>m;
        q.push({r,c});
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(m[{i,j}])
                continue;
            
            m[{i,j}]=true;
            
            int t = 0;
            
            if(i-1>=0 &&g[i][j]==g[i-1][j])
                t++,q.push({i-1,j});
            if(j-1>=0 && g[i][j]==g[i][j-1])
                t++,q.push({i,j-1});
            if(i+1<g.size() && g[i][j]==g[i+1][j])
                t++,q.push({i+1,j});
            if(j+1<g[0].size() && g[i][j]==g[i][j+1])
                t++,q.push({i,j+1});
            
         //   cout<<t<<" "<<i<<" "<<j<<" "<<g[i][j]<<"\n";
            if(t<4)
                q1.push({i,j});
            
        }

        while(!q1.empty())
        {
            int i = q1.front().first;
            int j = q1.front().second;
            g[i][j]=col;
            q1.pop();
        }
        return g;
    }
};

//[1,2,1,2,1,2]
//[2,2,2,2,1,2]
//[1,2,2,2,1,2]


//
//[1,1,1,1,1,2]
//[1,2,1,1,1,2]
//[1,1,1,1,1,2]


