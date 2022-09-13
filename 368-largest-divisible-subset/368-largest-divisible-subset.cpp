class Solution {
public:
    
    int dp[1001];
    vector<int>s;
    int f(vector<int>v,int i)
    {
        if(i==v.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        dp[i]=0;
        int m=0;
        for(int k = i+1;k<v.size();++k)
        {
            if(v[k]%v[i])
                continue;
            int h = f(v,k)+1;
            if(h>m)
            {
                m =h;
                s[i]=k;
            }
        }
        return dp[i]=m;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        s = vector<int>(nums.size(),INT_MAX);
        for(int i = 0;i<nums.size();++i)
        {
            f(nums,i);
        } 
        int y = 0;
        int m=0;
        for(int i =0;i<nums.size();++i)
            if(dp[i]>m)
            {
                y = i;
                m = dp[i];
            }
        vector<int>ans;
        while(ans.size()!=m+1)
        {
            ans.push_back(nums[y]);
            y =s[y];
        }
        return ans;
    }
};