class Solution {
public:
  long long  int dp[1001][1001];
    int mod = 1e9+7;
    int f(int i,int k,string &t,vector<vector<int>>&v)
    {
        if(i==t.size())return 1;
        if(k>=v.size())return 0;
        if(dp[i][k]!=-1)return dp[i][k]%mod;
        long long int ans = 0;
        
        long long p = v[k][t[i]-'a'];
        if(v[k][t[i]-'a']>=1)
            ans = ans%mod + (p*f(i+1,k+1,t,v)%mod)%mod;
        ans = ans%mod + f(i,k+1,t,v)%mod;
        return dp[i][k]=ans%mod;
    }
    int numWays(vector<string>& words, string target) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>v(words[0].size(),vector<int>(26));
        for(auto c:words)
        {
            for(int i = 0;i<c.size();++i)
                v[i][c[i]-'a']++;
            
        }
        
        return f(0,0,target,v);
    }
};