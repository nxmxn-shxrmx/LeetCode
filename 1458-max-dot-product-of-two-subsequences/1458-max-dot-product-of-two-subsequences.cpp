class Solution {
public:
    int dp[501][501];
    int f(int i,int j,vector<int>&v1,vector<int>&v2)
    {
        if(i==v1.size()||j==v2.size())return 0; 
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=max(f(i+1,j+1,v1,v2)+v1[i]*v2[j],max(f(i+1,j,v1,v2),f(i,j+1,v1,v2)));
    }
    int maxDotProduct(vector<int>& v1, vector<int>& v2) {
        memset(dp,-1,sizeof(dp));
        set<int>a1(v1.begin(),v1.end());
        if(*a1.rbegin()<0)
        {
            int ans = INT_MIN;
            for(auto c:v2)
                ans = max(ans,c*(*a1.rbegin()));
            return ans;
        }
        
        set<int>a2(v2.begin(),v2.end());
        if(*a2.rbegin()<0)
        {
            int ans = INT_MIN;
            for(auto c:v1)
                ans = max(ans,c*(*a2.rbegin()));
            return ans;
        }
        
        return f(0,0,v1,v2);
    }
};