class Solution {
public:
    int dp[201][201];
    bool f(string &s1,string &s2,string &s3,int i,int j)
    {
        if(i+j==s3.size())return 1;
        
        
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j]=0;
        if(i<s1.size()&&s3[i+j]==s1[i])
            dp[i][j]=f(s1,s2,s3,i+1,j);
        if(dp[i][j])
            return 1;
        if(j<s2.size()&&s3[i+j]==s2[j])
            dp[i][j]=f(s1,s2,s3,i,j+1);
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.size()+s2.size()!=s3.size())return 0;
        return f(s1,s2,s3,0,0);
    }
};