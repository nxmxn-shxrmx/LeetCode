class Solution {
public:
    int dp[21][5001];
    int f(int i,vector<int>v,int sum)
    {
        if(i==v.size())
        {
            if(sum==0)
                return 1;
            return 0;
        }
        int sum1=sum;
        if(sum1<0)
            sum1+=2000;
        
        if(dp[i][sum1]!=-1)
            return dp[i][sum1];
        
       return dp[i][sum1]=f(i+1,v,sum-v[i])+f(i+1,v,sum+v[i]);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums,target);
    }
};