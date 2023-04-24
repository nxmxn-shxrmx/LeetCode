class Solution {
public:
    int dp[2001][2004];
    long long int f(int i,int j,string &s)
{
	if(i==s.size()-1)
	{	
		
    bool k = 1;
    int p = i;
    int q = j;
  //      cout<<p<<" "<<q<<"\n";
    while(q<p)
    {
        
        if(s[p]!=s[q])
        {
            k= 0;
            break;
        }
        p--;
        q++;
    }
  //      cout<<k<<"\n";
        if(k)return 0;
		return INT_MAX;
	}
	if(dp[i][j]!=-1)return dp[i][j];
    bool k = 1;
    int p = i;
    int q = j;
    while(q<p)
    {
        if(s[p]!=s[q])
        {
            k= 0;
            break;
        }
        p--;
        q++;
    }
	if(k)
		return dp[i][j]= min(f(i+1,i+1,s)+1,f(i+1,j,s));
	return dp[i][j]=f(i+1,j,s);	
}
    int minCut(string s) {
            memset(dp,-1,sizeof(dp));
        return f(0,0,s);
    }
};