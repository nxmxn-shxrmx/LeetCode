class Solution {
public:
    int numSquares(int n) {
        vector<int>v(n+1);
        for(int i = 1;i<v.size();++i)
        {
             v[i]=INT_MAX;
             int p = ceil(sqrt(i));
            if(p*p==i)
                 v[i]=1;
            
            else
            while(p>=1)
            {
                if(i-p*p>=0)
                    v[i] = min(v[i-p*p]+1,v[i]);
                p--;
            }
        }
        
        
        return v[n];
    }
};