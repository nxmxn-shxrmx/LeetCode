class Solution {
public:
    int dp[1001][1001];
    long long mod=1e9+7;
    int f(int i,int j,int n)
    {
        
        if(i==j && n==i)
            return 1;
        if(n<i || n<j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int k =0;
        if(i==j)
           k=k%mod+f(i+1,j+1,n)%mod+f(i+2,j+2,n)%mod;
        k%=mod;
        if(j>i)
        k+=f(i+2,j,n)%mod;
          k%=mod;
        if(i>j)
        k+=f(i,j+2,n)%mod;
          k%=mod;
        if(i>=j)
            k+=f(i+1,j+2,n)%mod;
          k%=mod;
        if(j>=i)
            k+=f(i+2,j+1,n)%mod;
         k%=mod;
        
        return dp[i][j]=k%mod;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,n);
    }
};


// 1 1 1 2 
// 1 2 1 1 

// 1 2 1 1 
// 1 1 1 2 
    
// 2 1 1 1 
// 1 1 1 2 

// 2 1 1 1 
// 1 1 2 1 
    
// 1 1 1 2 
// 2 1 1 1 

// 1 1 2 1 
// 2 1 1 1 