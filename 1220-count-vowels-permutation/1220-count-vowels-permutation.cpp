class Solution {
public:
    map<char,vector<char>>m;
    map<pair<int,char>,long long>v;
    long long mod = 1000000007;
    
    
    long long pre(char a,int n)
    {
        if(n==0)
            return 1;
        
        if(v.find({n,a})!=v.end())
            return v[{n,a}]%mod;
        
        v[{n,a}]=0;
        
        for(auto c:m[a])
            v[{n,a}]=(v[{n,a}]%mod+pre(c,n-1)%mod)%mod,v[{n,a}]%=mod;
        
        return v[{n,a}]%mod;
    
    }
    
    int countVowelPermutation(int n) {
      
        m['a']={'e'};
        m['e']={'a','i'};
        m['i']={'a','u','e','o'};
        m['u']={'a'};
        m['o']={'i','u'};
        
        m['1']={'a','i','e','u','o'};
        return pre('1',n);
    }
};