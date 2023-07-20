class Solution {
public:
    int numberOfWays(string corridor) {
        int i = 0;
        while(i<corridor.size())
        {
            if(corridor[i]=='S')break;
            ++i;
        }
        long long pl = 0;
    long long se = 0;
        long long t  = 0;
        long long  ans = 1;
        long long mod =1e9+7;
        for(i;i<corridor.size();++i)
        {
            if(corridor[i]=='S')se++,t++;
            else if(corridor[i]=='P' && se==0)pl++;
            if(se==2)
            {
                ans = (ans%mod * (pl+1)%mod)%mod;
                ans%=mod;
                se = 0;
                pl=0;
            }
                
        }
        if(t==0||t%2)return 0;
      return ans;  
    }
};