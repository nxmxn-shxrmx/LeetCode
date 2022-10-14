class Solution {
public:
    map<int,int>m;
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(m[n]!=0)
            return m[n];
        m[n]=fib(n-1)+fib(n-2);
        return m[n];
    }
};