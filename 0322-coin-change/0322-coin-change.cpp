class Solution {
public:
    int coinChange(vector<int>& co, int n) {
        vector<long long>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            for(auto c:co)
            {
                if(i-c>=0 && dp[i-c]!=INT_MAX)
                    dp[i]=min(dp[i-c]+1,dp[i]);
            }
        }
        return dp[n]==INT_MAX?-1:dp[n];
    }
};