class Solution {
public:
vector<vector<int>>dp;
    int f(vector<int>&v,vector<int>&m,int l,int r,int i)
    {
        if(i==m.size())
            return 0;
        
        if(dp[i][l]!=INT_MIN)
        return dp[i][l];
        
        int k = INT_MIN;
        k = max(f(v,m,l+1,r,i+1)+v[l]*m[i],f(v,m,l,r-1,i+1)+v[r]*m[i]);
        return dp[i][l]=k;
    }
    int maximumScore(vector<int>& n, vector<int>& m) {
    dp = vector<vector<int>>(m.size(),vector<int>(m.size(),INT_MIN));
    int k= f(n,m,0,n.size()-1,0);
        return k;
    }
};