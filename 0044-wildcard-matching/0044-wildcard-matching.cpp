class Solution {
public:
   
    bool isMatch(string s, string p) 
    {
        int dp[s.size()+1][p.size()+1];
        memset(dp,0,sizeof(dp));
        dp[s.size()][p.size()]=1; 
        for(int i = p.size()-1;~i;--i)
        {
            if(p[i]=='*')
                dp[s.size()][i]=1;
            else
                break;
        }
    
        for(int i = s.size()-1;~i;--i)
        {
            for(int j = p.size()-1;~j;--j)
            {
                  if(p[j]=='*')
                    dp[i][j]=dp[i+1][j] || dp[i][j+1];
                  else if(p[j]=='?' || p[j]==s[i])
                    dp[i][j]=dp[i+1][j+1];
                else 
                    dp[i][j]=0;
            }
        }
        return dp[0][0];
    }
};