class Solution {
public:
   
    double myPow(double x, int n) {
        
        double ans = 1;
        int b = 0;
        if(n<0)b=1;
        while(n)
        {
            if(n&1)
                ans *=x;
            x*=x;
            n/=2;
        }
        if(b)ans = 1/ans;
        return ans;
    }
};