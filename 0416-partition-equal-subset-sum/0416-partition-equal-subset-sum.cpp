class Solution {
public:
    bool f(int i,int t,vector<int>&v)
    {
        if(t==0)return 1;
        if(i==v.size())return 0;
        
        return f(i+1,t,v)||f(i+1,t-v[i],v);
    }
    bool canPartition(vector<int>& nums) {
        int u  =0;
        for(auto c:nums)
            u+=c;
        if(u%2)return 0;
        
        u/=2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(u+1,0));
        for(int i = 1;i<=nums.size();++i)
                dp[i][0]=1;
        for(int i = 1;i<=nums.size();++i)
        {
            for(int j =1;j<=u;++j)
            {
                if(j-nums[i-1]>=0)
                    dp[i][j]|=dp[i-1][j-nums[i-1]];
                dp[i][j]|=dp[i-1][j];
            }
        }
        return dp[nums.size()][u];
    }
};