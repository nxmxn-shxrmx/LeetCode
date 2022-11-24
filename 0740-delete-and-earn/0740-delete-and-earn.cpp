class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    map<int,long long>m;
        int i = 1;
        int r = 0;
    for(auto c:nums)
        m[c]++,r = max(r,c);
    long long a = 0;
    long long b = 0;
    
    for(i;i<=r;++i)
    {
        if(i&1)
        {
            a+=m[i]*i;
            a = max(a,b);
        }
        else
        {
            b+=m[i]*i;
            b = max(a,b);
        }
    }
        return max(a,b);
    }
};