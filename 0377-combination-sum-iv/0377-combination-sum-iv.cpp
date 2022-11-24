class Solution {
public:
    long long dp[1001];
    long long mod =1e9+7;
    int combinationSum4(vector<int>& nums, int target) {
        dp[0]=1;
        for(int i = 1;i<=target;++i)
        {
            for(int j = 0;j<nums.size();++j)
            {
                if(i-nums[j]>=0)
                    dp[i]+=dp[i-nums[j]]%mod;
            }
        }
    
        return dp[target];
    }
};