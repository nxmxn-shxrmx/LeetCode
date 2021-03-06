class Solution {
public:
    int uniquePaths(int m, int n) {
        
        
        vector<vector<long long>>v(n,vector<long long>(m));
        
        for(int i = 0;i<m;++i)
            v[0][i]=1;
        for(int j = 0;j<n;++j)
            v[j][0]=1;
        
        v[0][0]=1;
        for(int i = 1;i<n;++i)
        {
            for(int j =1;j<m;++j)
            {
               v[i][j]+=v[i-1][j]+v[i][j-1];
            }
        }
        return v[n-1][m-1];
    }
};