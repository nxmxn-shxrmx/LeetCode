class Solution {
public:
    int dp[21][31];
    bool f(string s,string p,int i,int j)
    {
        if(i==s.size() && j==p.size())
            return 1;
        
        if(p.size()==j)
            return 0;
        if(s.size()==i)
        {
            for(int k = j;k<p.size();++k)
            {
                if(p[k]!='*')
                {
                    if(k+1<p.size() && p[k+1]=='*')
                        continue;
                    else
                        return 0;
                }
            } 
            return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j+1<p.size() && p[j+1]=='*')
            return dp[i][j]=f(s,p,i,j+1);
        if(p[j]=='*')
        {
            if(p[j-1]==s[i] || p[j-1]=='.')
                return dp[i][j]=f(s,p,i+1,j) || f(s,p,i,j+1);
            
            return dp[i][j]=f(s,p,i,j+1);
        }
        if(p[j]=='.' || p[j]==s[i])
               return dp[i][j]=f(s,p,i+1,j+1);
            return 0;
    }
    bool isMatch(string s, string p) {
        
        dp[s.size()][p.size()]=1;
        for(int i = p.size()-1;~i;--i)
        {
            if(p[i]=='*' && dp[s.size()][i+1])
                dp[s.size()][i]=1,dp[s.size()][i-1]=1;
        }
        for(int i = s.size()-1;~i;--i)
        {
            for(int j = p.size()-1;~j;--j)
            {
                if(j+1<p.size() && p[j+1]=='*')
                     dp[i][j]=dp[i][j+1];
                else if(p[j]=='*')
                {
                    if(p[j-1]==s[i] || p[j-1]=='.')
                        dp[i][j]=dp[i+1][j]||dp[i][j+1];
            
                    else
                        dp[i][j]=dp[i][j+1];
                }
                 else if(p[j]=='.' || p[j]==s[i])
                         dp[i][j]= dp[i+1][j+1];
                else
                    dp[i][j]=0;
            }
        }
        return dp[0][0];
    }
};