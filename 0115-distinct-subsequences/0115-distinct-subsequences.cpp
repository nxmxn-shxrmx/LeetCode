class Solution {
public:
    
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>>dp(s.size()+1,vector<unsigned long long>(t.size()+1));
        for(int i = 0;i<=s.size();++i)dp[i][t.size()]=1;
        for(int i = s.size()-1;~i;--i)
        {
            for(int j = t.size()-1;~j;--j)
            {
                dp[i][j] = dp[i+1][j];
                if(s[i]==t[j])
                    dp[i][j]+=dp[i+1][j+1];
            }
            
        }
        return dp[0][0];
    }
};                             