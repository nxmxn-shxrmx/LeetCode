class Solution {
public:
    int dp[101];
    int f(vector<int>&v,int i)
    {
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        return  dp[i]=max(f(v,i+1),f(v,i+2)+v[i]);
    }
    int rob(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return f(nums,0);
        // long long a=0,b=0;
        // for(int i = 0;i<nums.size();++i)
        // {
        //     if(i&1)
        //     {
        //         a = max(nums[i]+a,b);
        //     }
        //     else
        //     {
        //         b =max(nums[i]+b,a);
        //     }
        // }
        // return max(a,b);
    }
};