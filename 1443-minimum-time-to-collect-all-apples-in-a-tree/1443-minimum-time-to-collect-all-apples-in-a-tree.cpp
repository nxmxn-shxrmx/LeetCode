class Solution {
public:
    int c = 0;
    int f(int i,int pre,vector<vector<int>>&v,vector<bool>&a)
    {
        int k =0;
        if(v[i].size()==0)
            return a[i];
    
        for(auto c:v[i])
        {
            if(pre==c)
                continue;
            int g=f(c,i,v,a);
         //   cout<<i<<" "<<g<<"\n";
            k+=g;
        }
        if(i==0)
            return k;
        if(k==0)
            return a[i];
        
        return k+1;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>v(n);
        for(auto c:edges)
        {
            v[c[0]].push_back(c[1]);
            v[c[1]].push_back(c[0]);
        }
        return 2*f(0,-1,v,hasApple);
    }
};
