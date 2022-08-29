class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
        vector<vector<int>>v(m.size(),vector<int>(m[0].size(),INT_MAX));
        queue<pair<int,int>>q;
        for(int i =0;i<m.size();++i)
        {
            for(int j =0;j<m[0].size();++j)
            {
                if(m[i][j]==0)
                {
                    v[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dir[4][2]  = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            int i = q.front().first;
            int j =q.front().second;
            q.pop();
            for(auto c:dir)
            {
                
                int l =i+c[0];
                int r =j+c[1];
                if(l<0 || r<0 || l==m.size() || r==m[0].size())
                    continue;

                if(v[i][j]+1<v[l][r])
                {
                    v[l][r]=v[i][j]+1;
                    q.push({l,r});
                }
            }
        }
        
        return v;
    }
};