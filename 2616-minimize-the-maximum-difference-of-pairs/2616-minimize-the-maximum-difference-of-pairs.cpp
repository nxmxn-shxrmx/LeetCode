class Solution {
public:
    bool check(int k,int p,vector<int>&v)
    {
        int ct = 0;
        for(int i = 0;i<v.size()-1;++i)
        {
            if(abs(v[i]-v[i+1])<=k)
                ct++,++i;
        }
        return ct>=p;
    }
    int minimizeMax(vector<int>& v, int p) {
        sort(v.begin(),v.end());
        int l = 0;
    
        int r =v[v.size()-1]-v[0];
        int ans = r;
        while(l<=r)
        {
            int m =  (l+r)/2;
            if(check(m,p,v))
                ans = m,r = m-1;
            else l =m+1;
        }
        return ans;
    }
};
