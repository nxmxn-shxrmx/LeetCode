class Solution {
public:
    int coinChange(vector<int>& co, int n) {
        vector<long long>dp(n+1,0);
        
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            dp[i]=INT_MAX;
            for(auto c:co)
            {
                if(i-c>=0)
                    dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
        return dp[n]==INT_MAX?-1:dp[n];
    }
};