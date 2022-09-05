class Solution {
public:
    vector<vector<int>>v;
    void reuc(int k,int n,vector<int>p,int i)
    {
        if(k==0)
        {
            v.push_back(p);
            return;
        }
        for(int j=i+1;j<=n;++j)
        {
            p.push_back(j);
            reuc(k-1,n,p,j);
            p.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        for(int i=1;i<=n;++i)
        {
            vector<int>p;
            p.push_back(i);
            reuc(k-1,n,p,i);
            p.pop_back();
        }
        return v;
    }
};