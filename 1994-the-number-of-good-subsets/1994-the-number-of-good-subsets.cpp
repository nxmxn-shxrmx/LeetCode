class Solution {
public:
   int ans = 0;
   int mod = 1e9+7;
   map<int,int>m,b;
    int gcd(int a ,long long int b)
{
   for(int i = 2;i<=30;++i)
   {
       if(a%i==0 && b%i==0)return 0;
   }
        return 1;
}
    void f(int i,long long p,long long g,vector<int>&v)
    {
        if(i==v.size())
        {
            if(p!=1)
                ans = (ans%mod + g%mod)%mod;
            
            return;
        }
        if(gcd(v[i],p)==1)
            f(i+1,p*v[i],(g%mod*m[v[i]])%mod,v);
          
        
        f(i+1,p,g,v);
    }
    int numberOfGoodSubsets(vector<int>& nums) {
    
  
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
  
    f(0,1,1,v);
    long long t =1;
    for(int i =0;i<m[1];++i)
        t =(t%mod *2)%mod;
        
    ans = (ans%mod *t%mod)%mod;
    return ans;  
    }
};