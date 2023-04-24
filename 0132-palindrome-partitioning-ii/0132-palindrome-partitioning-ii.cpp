class Solution {
public:
    int dp[2001][2004];
    int check[2001][2001];
    long long int f(int i,int j,string &s)
{
	if(i==s.size()-1)
	{	
		
        if(s[i]==s[j]&&((i-j<2)||check[j+1][i-1]))return 0;
		return INT_MAX;
	}
	if(dp[i][j]!=-1)return dp[i][j];
    bool k = 0;
        
            
    if(s[i]==s[j]&&((i-j<2)||check[j+1][i-1]))k =1;
    if(k)
        check[j][i]=1;
    
	if(k)
		return dp[i][j]= min(f(i+1,i+1,s)+1,f(i+1,j,s));
	return dp[i][j]=f(i+1,j,s);	
}
    int minCut(string s) {
            memset(dp,-1,sizeof(dp));
        return f(0,0,s);
    }
};