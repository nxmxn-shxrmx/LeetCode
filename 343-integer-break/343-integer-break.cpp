class Solution {
public:
    vector<int>dp;
    int Break(int n) {
    
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        
        for(int i = 1;i<n;++i)
        {
            dp[n] = max(i*(n-i),dp[n]);
            dp[n] = max(dp[n],Break(n-i)*i);
        }
        return dp[n];
    }
    int integerBreak(int n) {
        dp = vector<int>(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        return Break(n);
    }
};