class Solution {
public:
    int coinChange(vector<int>& v, int x) {
    
     vector<long long>p(x+1);
    p[0]=0;
    for(long long i = 1;i<=x;++i)
    {
        p[i]=INT_MAX;
        for(auto c:v)
        {
            if(i-c>=0)
            p[i] = min(p[i],p[i-c]+1);
        }
    }

    if(p[x]==INT_MAX)
    return -1;

    else
    return  p[x];

    }
};