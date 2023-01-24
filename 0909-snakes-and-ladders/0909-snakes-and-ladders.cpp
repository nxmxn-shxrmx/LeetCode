class Solution {
public:
    int dp[500][500];
    int ch[500];
    int f(int n,int i,int pre,vector<vector<int>>&b)
    {
         if(ch[i])return 1000;
        
        if(i==((n*n)-1))return dp[i][pre]=0;
        if(dp[i][pre]!=-1)return dp[i][pre];
        int ans = 1000;
        ch[i]=1;
        for(int k = min(i+6,n*n-1);k>=(i+1);--k)
        {
            
              int r = k/n;
              int c = k%n;
              int u = k;
              if(b[r][c]!=-1)u = b[r][c]-1;
              
            ans = min(ans,f(n,u,pre+1,b)+1);
                
        }
         ch[i]=0;
        return dp[i][pre]=ans;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>v;
        int p = 0;
        for(int i= board.size()-1;~i;--i)
        {
            if(p)
                reverse(board[i].begin(),board[i].end());
            v.push_back(board[i]);
            p = !p;
        }
       
        
        int u=f(board.size(),0,0,v);
        if(u>=1000)u=-1;
     
        return u;
    }
};