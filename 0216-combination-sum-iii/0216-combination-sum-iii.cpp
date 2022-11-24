class Solution {
public:
    vector<vector<int>>v;
    void f(int i,int k,int n,vector<int>b)
    {
        if(n==0 && k==0)
        {
            v.push_back(b);
            return;
        }
        if(n<=0 || k==0 || i==10)
            return;
        for(int p = i;p<=9;++p)
        {
            b.push_back(p);
            f(p+1,k-1,n-p,b);
            b.pop_back();
        }
            
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int u = n*(n+1);
        u/=2;
        if(u<n || k>n)
       return {}; 
        vector<int>b;
        f(1,k,n,b);
      return v;  
    }
};