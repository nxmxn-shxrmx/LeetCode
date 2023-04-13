class Solution {
public:
    int dp[501][501];
    int f(int i,int j,vector<int>&v1,vector<int>&v2)
    {
        if(i==v1.size()|| j==v2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(v1[i]==v2[j])
            return dp[i][j]=max(f(i+1,j+1,v1,v2)+1,max(f(i,j+1,v1,v2),f(i+1,j,v1,v2)));
        
        return dp[i][j]=max(f(i,j+1,v1,v2),f(i+1,j,v1,v2));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,nums1,nums2);
    }
};