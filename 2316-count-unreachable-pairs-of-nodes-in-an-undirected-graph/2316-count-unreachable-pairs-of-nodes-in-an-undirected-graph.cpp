class Solution {
public:
    vector<bool>b;
    int dfs(int i,vector<vector<int>>&g)
    {
        b[i]=true;
        int k = 0;
        for(auto c:g[i])
        {
            if(!b[c])
            {
            k+=    dfs(c,g);
            
            }
        }
        return k+1;
        
    }
    long long countPairs(int n, vector<vector<int>>& e) {
        if(e.size()==0)
        {
            n--;
            long long p =n;
            return  p*(p+1)/2;
        }
        vector<vector<int>>g(n);
        b = vector<bool>(n);
        
        n--;
        long long p = n;
         p = p*(p+1)/2;
        n++;
        for(auto c:e)
        {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        
        for(int i =0;i<n;++i)
        {
            if(!b[i])
            {
                long long h=dfs(i,g);
                h--;
                h = h*(h+1)/2;
                p-=h;
            }
        }
        
        return p;
    }
};