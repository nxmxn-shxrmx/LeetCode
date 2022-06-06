class Solution {
public:
     int findNumberOfLIS(vector<int>& nums) {
      vector<int>dp(nums.size());
         vector<int>l(nums.size());
         int c= 0;
         for(int i = 0;i<nums.size();++i)
         {
             dp[i] =1;
             l[i]=1;
             for(int j = 0;j<i;++j)
             {
                 if(nums[j]<nums[i])
                 {
                     if(dp[j]+1>dp[i])
                     {
                         dp[i] = dp[j]+1;
                         l[i]=l[j];
                     }
                     else if(dp[j]+1==dp[i])
                         l[i]+=l[j];
                 }
             }
             c = max(c,dp[i]);
         }
         
         long long ans =0;
         for(int i = 0;i<dp.size();++i)
         {
             if(dp[i]==c)
                 ans+=l[i];
         }
         return ans;
         
    }
};
