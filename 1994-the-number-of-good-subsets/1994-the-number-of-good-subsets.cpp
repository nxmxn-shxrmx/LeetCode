class Solution {
public:
    vector<vector<int>>ans;
    int gcd(int a ,long long int b)
{
   for(int i = 2;i<=30;++i)
   {
       if(a%i==0 && b%i==0)return 0;
   }
        return 1;
}
    void f(int i,long long p,vector<int>&g,vector<int>&v)
    {
        if(i==v.size())
        {
            if(p!=1)
                ans.push_back(g);
            return;
        }
        if(gcd(v[i],p)==1)
        {
            g.push_back(v[i]);
            f(i+1,p*v[i],g,v);
            g.pop_back();
        }
        f(i+1,p,g,v);
    }
    int numberOfGoodSubsets(vector<int>& nums) {
    
    map<int,int>m,b;
    for(int i = 2;i<=30;++i)
    {
        bool p = 0;
        for(int j = 2;j<=sqrt(i);++j)
            if(i%j==0)
            {
                p =1;
                break;
            }
        if(!p)
            b[i]=1;
    }
    b[6]=1;
    b[10]=1;
    b[14]=1;
    b[15]=1;
    b[21]=1;
    b[22]=1;
    b[26]=1;
    b[30]=1;
    vector<int>v;
    for(auto c:nums)
    {
        if(c==1)
        {
            m[c]++;
            continue;
            
        }
        if(b[c])
        {
            m[c]++;
            if(m[c]==1)v.push_back(c);
        }
    }
    vector<int>g;
    f(0,1,g,v);
        long long a = 0;
        int mod = 1e9+7;
    for(auto c:ans)
    {
        long long u = 1;
        for(auto x:c)
        {
    
            u= (u%mod*m[x])%mod;
        }
       
        a = (a%mod + u%mod)%mod;
    }
     
    long long t =1;
    for(int i =0;i<m[1];++i)
        t =(t%mod *2)%mod;
    a = (a%mod *t%mod)%mod;
    return a%mod;  
    }
};