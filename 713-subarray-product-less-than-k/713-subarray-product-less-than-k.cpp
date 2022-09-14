class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        if(k==0)
            return 0;
        long long p =1;
        long long x = 0;
        int j = 0;
        for(int i = 0;i<size(v);++i)
        {
        
            p*=v[i];
             while(j<=i && p>=k)
             {
                 p/=v[j];
                ++j;
             }
            x += i-j+1;
    
        }
        return x;
    }
};