class Solution {
public:
    long long dp[10001];
    long long f(int i,vector<int>&v)
    {
        if(i>=v.size()-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        long long k = INT_MAX;
        
        for(int j =i+1;j<=v[i]+i;++j)
            k = min(k,f(j,v)+1);
        return dp[i]=k;
    }
    int jump(vector<int>&v) {
        memset(dp,-1,sizeof(dp));
      return f(0,v);
    }
};