class Solution {
public:
    
    #define ll long long
    #define mod (ll)(1e9 +7)
    const int N = 1e6 + 10;
    int n;
    string r = "";
    string u ="";
    bool check(int m,string s)
    {
        unordered_map<int, vector<int>> mi;
        for(int i = m;i<=n;++i)
        {
            ll k = le[i];
            ll h = (po[m]%mod*(le[i-m]%mod))%mod;
            k = ((k%mod - h%mod) + mod)%mod;
            
             
            if(mi[k].size()==0)
                mi[k].push_back(i-m);
         
            else 
            {
                for(auto c:mi[k])
                {
                    
                    if(strcmp((s.substr(i-m,m)).data(), s.substr(c,m).data()) == 0)
                    {
                        u = s.substr(i-m,m);
                        return 1;
                    }
                }
                mi[k].push_back(i-m);
            }
        }
        return 0;
    }
    
    ll le[100000];
    ll po[100000];
    string longestDupSubstring(string s) {
        n = s.size();
        po[0]=1;
        po[1]=1;
        ll p =1;
        for(int i =1;i<=s.size();++i)
        {
            le[i] = ((le[i-1]*101)%mod + (s[i-1]-'a'+1)%mod)%mod;
            
            po[i]=(po[i-1]*101)%mod;

        }
        int ri = s.size()-1;
        int l = 1;
        while(l<=ri)
        {
            int m = (l+ri)/2;
            if(check(m,s))
                r=u,l = m+1;
            else
                ri = m-1;    
        }
        return u;
    }
};