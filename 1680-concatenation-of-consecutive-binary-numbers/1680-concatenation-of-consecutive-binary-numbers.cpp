class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1000000007;
        long long sum = 0;
        for(int i = 1;i<=n;++i)
        {
            int l = log2(i)+1;
            sum = ((sum<<l)|i)%mod;
        }
        return (int) sum;
    }
};