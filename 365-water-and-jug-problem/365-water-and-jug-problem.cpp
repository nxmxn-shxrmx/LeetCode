class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        
        if(j1+j2<t)
            return false;
        if(j1==t || j2==t || j1+j2==t ||t%(__gcd(j1,j2))==0)
            return true;
        
        return false;
        
    }
};