class Solution {
public:
    
    vector<vector<int>>v;
 
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
       
        v=vector<vector<int>>(m.size(),vector<int>(m[0].size(),INT_MAX));
        queue<pair<int,int>>q;
        for(int i= 0;i<m.size();++i)
        {
            for(int j = 0;j<m[0].size();++j)
            {
                if(m[i][j]==0)
                {
                    v[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dir[4][2] ={{1,0},{-1,0},{0,-1},{0,1}};
    
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto c:dir)
            {
                int ni = i+c[0];
                int nj = j+c[1];
                
                if(ni<0 || nj<0 || ni>=m.size() || nj>=m[0].size())
                    continue;
                
                if(v[ni][nj]>v[i][j]+1)
                {
                    v[ni][nj]=v[i][j]+1;
                    q.push({ni,nj});
                }
            }
                
        }
      
        return v;
    }
};