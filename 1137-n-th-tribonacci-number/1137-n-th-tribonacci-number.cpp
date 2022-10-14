class Solution {
public:
    map<int,int>m;
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        if(m[n]!=0)
            return m[n];
        
        return m[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};