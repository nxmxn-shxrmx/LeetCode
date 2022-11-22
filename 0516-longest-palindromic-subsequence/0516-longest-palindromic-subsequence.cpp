class Solution {
public:
//     int dp[3001][3001];
//     int f(int i,int j,string s)
//     {
//         if(i>j)
//             return 0;
//         if(i==j)
//             return 1;
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         if(s[i]==s[j])
//             return dp[i][j]=f(i+1,j-1,s)+2;
//         return dp[i][j] = max(f(i+1,j,s),f(i,j-1,s));
            
//     }
    int longestPalindromeSubseq(string s) {
      
        int n = s.size();
        vector<int>cur(n+1);
        vector<int>pre(n+1);
        for(int i = s.size()-1;~i;--i)
        {
            for(int j = 1;j<=s.size();++j)
            {
                if(i>j)
                    continue;
                if(i==j)
                    cur[j]=1;
               else if(s[n-i-1]==s[n-j]) cur[j]=pre[j-1]+2;
                
                else cur[j] = max(pre[j],cur[j-1]);   
            }
            pre= cur;
        }
        // for(int i = 0;i<=s.size();++i)
        // {
        //     for(int j = 0;j<=s.size();++j)
        //         cout<<dp[i][j]<<" ";
        //     cout<<"\n";
        // }
        return cur[s.size()]-1;
    }
};