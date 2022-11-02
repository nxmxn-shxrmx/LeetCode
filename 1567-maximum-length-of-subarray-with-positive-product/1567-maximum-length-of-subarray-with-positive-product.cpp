class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int u = 0;
        int t = 0;
        int l = 1;
        int p = 0;
        int o =0;
        for(auto c:nums)
        {
            if(c==0)
            {
            if(p==1)
            u =max(u,t-o);
                t = 0;
                l = 1;
                p = 0;
                o = 0;
                continue;
            }
        
            if(c<0)
                l*=-1;
            ++t;
            if(l==1)
            {
                u = max(t,u);
            }
            if(p==0)
            {
                o++;
                if(l<0)
                    p=1;
            }
        }
        if(p==1)
            u =max(u,t-o);
        return u;
    }
};