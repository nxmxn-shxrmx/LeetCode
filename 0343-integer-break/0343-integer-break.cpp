class Solution {
public:
    vector<int>dp;
    int integerBreak(int n) {
        dp = vector<int>(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i = 3;i<=n;++i)
        {
            for(int j = 1;j<=i;++j)
            {
                dp[i] = max(j*(i-j),dp[i]);
                dp[i] = max(j*dp[i-j],dp[i]);
            }
        }
     return dp[n];
        // if(n==2)
        //     return 1;
        // if(n==3)
        //     return 2;
        // int pp = 1;
        // while(n>4)
        // {
        //     pp*=3;
        //     n-=3;
        // }
        // return n*pp;
    }
};