class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>v(n);
        v[0]=1;
        int i2=0;
        int i3=0;
        int i5=0;
        for(int i=1;i<n;++i)
        {
            int k = min(min(v[i2]*2,v[i3]*3),v[i5]*5);
            v[i]=k;
            if(k==v[i2]*2)i2++;
            if(k==v[i3]*3)i3++;
            if(k==v[i5]*5)i5++;
        }
        
        return v[n-1];
    }
};