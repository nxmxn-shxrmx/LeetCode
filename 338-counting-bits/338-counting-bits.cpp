class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        if(n==0)
            return {0};
        if(n==1)
            return {0,1};
        
        v[0]=0;
        v[1]=1;
        int i =0;
        for(int j = 2;j<=n;++j)
        {
            if(ceil(log2(j))==floor(log2(j)))
            i=0;
            v[j]+=v[i]+1;
            ++i;
            
        }
    return v;
    }
};