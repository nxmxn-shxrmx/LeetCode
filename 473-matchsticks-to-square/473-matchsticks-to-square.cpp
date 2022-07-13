class Solution {
public:
    
    bool makesquare(vector<int>& m) {
        int sum=0;
        for(auto c:m)
            sum+=c;
        if(sum%4)
            return false;
        sort(m.begin(),m.end());
        int n= m.size();
        sum/=4;
        if(m[n-1]>sum)
            return false;
        vector<int>dp((1<<n)+1,-1);
        dp[0]=0;
        for(int i =0;i<(1<<n);++i)
        {
            if(dp[i]==-1)
                continue;
            for(int j = 0;j<n;++j)
            {
                if(!(i&(1<<j))&&dp[i]+m[j]<=sum)
                {
                    dp[i|(1<<j)]=(dp[i]+m[j])%sum;
                }
            }
        }
        return dp[(1<<n)-1]==0;
        
    }
};