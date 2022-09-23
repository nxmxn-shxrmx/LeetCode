class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1000000007;
        long long sum = 0;
        int l = 0;
        for(int i = 1;i<=n;++i)
        {
            if((i&(i-1))==0)
                l++;
            sum = ((sum<<l)|i)%mod;
        }
        return (int) sum;
    }
};