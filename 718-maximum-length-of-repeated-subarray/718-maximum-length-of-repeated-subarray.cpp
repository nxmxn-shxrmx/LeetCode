class Solution {
public:
    
    #define ll unsigned long long
    #define mod (ll)(1e9 +7)
    
    
    vector<ll>po;
    bool check(vector<ll>p,vector<ll>q,int m)
    {
        map<ll,bool>s;
        for(int i = m;i<p.size();++i)
        {
             ll k = p[i]-p[i-m]*po[m];
             s[k]=1;
        
        }
         for(int i = m;i<q.size();++i)
        {
             ll k = q[i]-q[i-m]*po[m];
             if(s[k])
                 return true;
    
        }
    
        return false;
    }
    int findLength(vector<int>& a, vector<int>& b) {
        if(b.size()>a.size())
            swap(a,b);
        
        vector<ll>p(a.size()+1);
        vector<ll>q(b.size()+1);
        po = vector<ll>(a.size()+1);
        po[0]=1;
        int l =0;
        for(int i = 1;i<=a.size();++i)
            p[i] = (p[i-1]*107) + (a[i-1]+1),po[i]=(po[i-1]*107);

    
        for(int i = 1;i<=b.size();++i)
            q[i] = (q[i-1]*107) + (b[i-1]+1);
        
    
        int ans = 0;
        int r = q.size();
        while(l<=r)
        {
            int m = (l+r)/2;
            if(check(p,q,m))
            {
                l = m+1;
                ans = m;
            }
            else
                r = m-1;
        }
        return  ans;
    }
};

    