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
        if(n==0 || k==0 || i==10)
            return;
        b.push_back(i);
        f(i+1,k-1,n-i,b);
        b.pop_back();
        f(i+1,k,n,b);
            
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