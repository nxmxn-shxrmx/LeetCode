class Solution {
public:
    int dp[501][501];
    int f(int i,int j,string &s)
    {
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==s[j])
            return dp[i][j] = f(i+1,j-1,s);
        return dp[i][j] = min(f(i+1,j,s)+1,f(i,j-1,s)+1);
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s.size()-1,s);
    }
};