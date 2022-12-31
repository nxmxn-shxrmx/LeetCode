class Solution {
public:
    int trap(vector<int>& h) {
        
        long long s = 0;
        long long i1 = h[0];
        long long i2 = h[h.size()-1];
        vector<pair<int,int>>v(h.size());
        v[0].first = i1;
        v[h.size()-1].second=i2;
        for(int i =1,j = h.size()-2;j>=0;--j,++i)
        {
            if(h[i]>i1)
            i1 = h[i];
            v[i].first = i1;
            if(h[j]>i2)
            i2 = h[j];
            v[j].second = i2;
        }

        for(int i = 0;i<h.size();++i)
        {
            int f = v[i].first;
            if(f>v[i].second)
                f = v[i].second;
            s+=(f-h[i]);
        }
        return s;
    }
};