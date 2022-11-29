class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,vector<vector<int>>&m)
    {
    
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=1;
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto c:d)
        {
            int x = i+c[0];
            int y = j+c[1];
            if(x<0 || y<0 || y>=m[0].size() || x>=m.size() || m[x][y]==-1 || m[x][y]<=m[i][j])
            continue;
            
            int t =-1;
            swap(t,m[i][j]);
            dp[i][j]=max(dp[i][j],f(x,y,m)+1);
            swap(t,m[i][j]);
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& m) {
        dp = vector<vector<int>>(m.size()+1,vector<int>(m[0].size()+1,-1));
        int ans = 0;
        for(int i = 0;i<m.size();++i)
        {
            for(int j = 0;j<m[0].size();++j)
            {
                ans = max(f(i,j,m),ans);   
            }
        }
        // for(auto c:dp)
        // {
        //     for(auto x:c)
        //     cout<<x<<" ";
        //     cout<<"\n";
        // }
        return ans;
    }
};
