class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g){
        int n=g.size();
        vector<vector<int>>v(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        if(g[0][0]==0)
            q.push({0,0}),v[0][0]=0;
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
           if(i-1>=0 && g[i-1][j]==0 && v[i][j]+1<v[i-1][j])
           {
               v[i-1][j]=v[i][j]+1;
               q.push({i-1,j});
           }
            if(i-1>=0 && j-1>=0 && g[i-1][j-1]==0 && v[i-1][j-1]>v[i][j]+1)
            {
                v[i-1][j-1]=v[i][j]+1;
               q.push({i-1,j-1});
            }
            if(i-1>=0 && j+1<n && g[i-1][j+1]==0 && v[i-1][j+1]>v[i][j]+1)
            {
                v[i-1][j+1]=v[i][j]+1;
               q.push({i-1,j+1});
            }
            if(j-1>=0 && g[i][j-1]==0 && v[i][j]+1<v[i][j-1])
            {
                v[i][j-1]=v[i][j]+1;
                q.push({i,j-1});
            }
            if(j+1<n && g[i][j+1]==0 && v[i][j]+1<v[i][j+1])
            {
                v[i][j+1]=v[i][j]+1;
                q.push({i,j+1});
            }
            
             if(i+1<n && g[i+1][j]==0 && v[i][j]+1<v[i+1][j])
           {
               v[i+1][j]=v[i][j]+1;
               q.push({i+1,j});
           }
            if(i+1<n && j-1>=0 && g[i+1][j-1]==0 && v[i+1][j-1]>v[i][j]+1)
            {
                v[i+1][j-1]=v[i][j]+1;
               q.push({i+1,j-1});
            }
            if(i+1<n && j+1<n && g[i+1][j+1]==0 && v[i+1][j+1]>v[i][j]+1)
            {
                v[i+1][j+1]=v[i][j]+1;
               q.push({i+1,j+1});
            }
            
         
        }
        
        return v[n-1][n-1]==INT_MAX?-1:v[n-1][n-1]+1;
    }
};