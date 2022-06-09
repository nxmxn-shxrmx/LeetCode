class Solution {
public:
    
    #define ll long long
    #define mod (ll)(1e9 +7)

    string longestPrefix(string s) {
    
        int n =  s.size();
        ll le=0;
        ll re=0;
        ll p =1;
        ll k =0;
        for(int i = 0;i<n-1;++i)
        {
            le =( (le*31)%mod + (s[i]-'a'+1))%mod;
            re =( ( (s[n-i-1]-'a'+1)*p )%mod + re%mod )%mod;
            if(le==re)
                k=n-i-1;
            p = (p*31)%mod;
        }
        if(k==0)
            return "";
        
        return s.substr(k);
    }
};