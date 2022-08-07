class Solution {
public:
    map<char,vector<char>>m;
    map<char,int>l;
    long long v[20001][6];
    long long mod = 1000000007;
    
    
    long long pre(char a,int n)
    {
        if(n==0)
            return 1;
        
        if(v[n][l[a]]!=-1)
            return v[n][l[a]]%mod;
        
         v[n][l[a]]=0;
        
        for(auto c:m[a])
        {
            v[n][l[a]] = (v[n][l[a]]%mod +pre(c,n-1)%mod);
            v[n][l[a]]%=mod;
        }
        
        return v[n][l[a]]%mod;
    
    }
    
    int countVowelPermutation(int n) {
      
        m['a']={'e'};
        m['e']={'a','i'};
        m['i']={'a','u','e','o'};
        m['u']={'a'};
        m['o']={'i','u'};
        
        m['1']={'a','i','e','u','o'};
        l['1']=0;
        l['a']=1;
        l['e']=2;
        l['o']=3;
        l['u']=4;
        l['i']=5;
        
        memset(v,-1,sizeof(v));
        
        return pre('1',n);
    }
};