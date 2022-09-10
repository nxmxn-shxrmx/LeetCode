class Solution {
public:
    int dp[2][101][1001];
    
    int recurse(int i,int p,int k,vector<int>pr)
    {
        if(i==pr.size() || (k==0 && p))
            return 0;
        
        if(dp[p][k][i]!=-1)
            return dp[p][k][i];
        int u = pr[i];
        if(p)
            u*=-1;
        return dp[p][k][i] = max(recurse(i+1,p,k,pr) ,u+recurse(i+1,!p,k-p,pr));
            
    }
    int maxProfit(int k, vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        return recurse(0,1,k,p);
    }
};