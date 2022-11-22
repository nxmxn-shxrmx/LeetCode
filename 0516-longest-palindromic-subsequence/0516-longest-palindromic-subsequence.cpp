class Solution {
public:
    int dp[3001][3001];
    int f(int i,int j,string s)
    {
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j])
            return dp[i][j]=f(i+1,j-1,s)+2;
        return dp[i][j] = max(f(i+1,j,s),f(i,j-1,s));
            
    }
    int longestPalindromeSubseq(string s) {
        for(int i = 0;i<s.size();++i)
            dp[i][i]=1;
        int n = s.size();
        for(int i = s.size()-1;~i;--i)
        {
            for(int j = 1;j<=s.size();++j)
            {
                if(i>=j)
                    continue;
                
                if(s[n-i-1]==s[n-j]) dp[i][j]=dp[i+1][j-1]+2;
                
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);   
            }
        }
        // for(int i = 0;i<=s.size();++i)
        // {
        //     for(int j = 0;j<=s.size();++j)
        //         cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        return dp[0][s.size()]-1;
    }
};