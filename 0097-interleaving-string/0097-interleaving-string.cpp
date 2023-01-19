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
        if(s1.size()+s2.size()!=s3.size())return 0;
        dp[s1.size()][s2.size()]=1;
        for(int i = s3.size()-1;~i;--i)
        {
            for(int j = s3.size()-1;~j;--j)
            {
                if(i<s1.size()&&(i+j)<s3.size()&&s1[i]==s3[i+j])
                    dp[i][j]=dp[i+1][j];
                if(j<s2.size()&&(i+j)<s3.size()&&s2[j]==s3[i+j])
                    dp[i][j]|=dp[i][j+1];
                
            }
        }
        return dp[0][0];
    }
};