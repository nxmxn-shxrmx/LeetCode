class Solution {
public:
    int dp[100001];
    bool f(int i,vector<int>&v)
    {
        
        if(i==v.size())return 1;
        
        if(dp[i]!=-1)return dp[i];
        if(i+1<v.size() && v[i]==v[i+1]&&f(i+2,v))return 1;
        if(i+2<v.size() && v[i]==v[i+1] && v[i]==v[i+2]&&f(i+3,v))return 1;
        if(i+2<v.size() && v[i]+1==v[i+1] && v[i+1]+1==v[i+2] &&f(i+3,v))return 1;        
        return dp[i]=0;
        
    }
    bool validPartition(vector<int>& nums) {
        if(nums.size()==1)return 0;
        memset(dp,-1,sizeof(dp));
        return f(0,nums);
    }
};