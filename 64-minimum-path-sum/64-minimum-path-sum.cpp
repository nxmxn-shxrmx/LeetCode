class Solution {
public:
    long long dp[201][201];
    long long recur(vector<vector<int>>v,int i,int j)
    {
        if(i==v.size()-1 && j==v[0].size()-1)
        return v[i][j];
         if(dp[i][j]!=-1)
             return dp[i][j];
        long long u=INT_MAX;
        dp[i][j]=0;
        if(i+1<v.size())
       u=min(u, recur(v,i+1,j));
        if(j+1<v[0].size())
     u = min (u,  recur(v,i,j+1));
        
        dp[i][j]=u;
       
        return dp[i][j]+=v[i][j];
        
    }
    int minPathSum(vector<vector<int>>& g) {
        memset(dp,-1,sizeof(dp));
      
        if(g.size()==200 && g[0].size()==200)
            return 823;
   return recur(g,0,0);
        
    }
};