class Solution {
public:
    // int dp[101];
    // int f(vector<int>&v,int i)
    // {
    //     if(i>=v.size())return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     return  dp[i]=max(f(v,i+1),f(v,i+2)+v[i]);
    // }
    int rob(vector<int>& nums) {
        
        // vector<int>dp(nums.size()+1);
        // for(int i = 1;i<=nums.size();++i)
        // {
        //     int g = 0;
        //     if(i-2>=0)
        //         g = dp[i-2];
        //     dp[i] = max(dp[i-1],g+nums[i-1]);
        // }
        // return dp[nums.size()];
        long long a=0,b=0;
        for(int i = 0;i<nums.size();++i)
        {
            if(i&1)
            {
                a = max(nums[i]+a,b);
            }
            else
            {
                b =max(nums[i]+b,a);
            }
        }
        return max(a,b);
    }
};