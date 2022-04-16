class Solution {
public:
    vector<int>dp;
    int integerBreak(int n) {
        dp = vector<int>(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i = 1;i<=n;++i)
        {
            for(int j = 1;j<=i;++j)
            {
                dp[i] = max(j*(i-j),dp[i]);
                dp[i] = max(j*dp[i-j],dp[i]);
            }
        }
        return dp[n];
    }
};