class Solution {
public:
    long long dp[5001];
    // long long mod =1e9+7;
    int change(int target, vector<int>&nums) {
        dp[0]=1;
        for(auto j:nums)
        {
            for(int i = 1;i<=target;++i)
            {
                if(i-j>=0)
                    dp[i]+=dp[i-j];
            }
        }
    
        return dp[target];
    }
};