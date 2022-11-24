class Solution {
public:
    map<int,int>m;
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(m[n]!=0)
            return m[n];
        m[n]=climbStairs(n-2)+climbStairs(n-1);
        return m[n];
    }
};