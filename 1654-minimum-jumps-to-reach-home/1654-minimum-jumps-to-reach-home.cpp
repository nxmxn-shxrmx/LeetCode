class Solution {
public:
    map<pair<int,int>,bool>m;
    int g = INT_MIN;
    int dfs(int i,int x,int a,int b,int pre=1)
    {
        if(i==x)
            return 0;
    
        if(i<0 || m[{pre,i}] ||g<i)
            return -1;
    
        m[{pre,i}]=true;
        
        int k = INT_MAX;
        int h = dfs(i+a,x,a,b,1);
        if(h>=0)
            k =h;
        if(pre==1)
        {
            int u = dfs(i-b,x,a,b,0);
            if(u>=0)
                k = min(k,u);
        }
        
        return k==INT_MAX?-1:k+1;
        
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(auto c:forbidden)
            m[{0,c}]=true,m[{1,c}]=true,g = max(c+a+b,g);
        
        g = max(x+a+b,g);
        return dfs(0,x,a,b);
    }
};