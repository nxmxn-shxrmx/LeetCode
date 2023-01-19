class Solution {
public:
    int dp[201][201];
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