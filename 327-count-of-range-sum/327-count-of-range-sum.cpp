class Solution {
public:
    vector<long long>v;
    int c = 0;
    set<pair<int,pair<int,int>>>p;
    void merge(int l,int m,int r,int lo,int up)
    {
        vector<long long>e(r-l+1);
        int t = m+1;
        int h = m+1;
        int re= m+1;
        int j =0;
        for(int i =l;i<=m;++i)
        {
            while(t<=r && v[t]-v[i]<lo)
                ++t;
            while(h<=r && v[h]-v[i]<=up)
                ++h;
            while(re<=r && v[re]<v[i])
                e[j++]=v[re++];
            c+=(h-t);
            e[j++]=v[i];
        }
        while(re<=r)
            e[j++]=v[re++];
       // cout<<"\n";
      //  cout<<l<<" "<<m<<" "<<r<<"\n";
        for(int i = l;i<=r;++i)
            v[i] = e[i-l];
        
     //   cout<<"\n\n\n";
       // cout<<h<<" "<<t<<"\n";
      //  c+=(h-t);
    }
    void div(int l,int r,int lo,int up)
    {
        if(l<r)
        {    
            int m=(l+r)/2;
            div(l,m,lo,up);
            div(m+1,r,lo,up);
            merge(l,m,r,lo,up);
        }
    }
    int countRangeSum(vector<int>& nums, int l, int u) {
        v.push_back(0);
        long long s=0;
        for(auto x:nums)
        {
            s+=x;
            v.push_back(s);
        }
       div(0,nums.size(),l,u);
        return c;
        
    }
};