class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int t = 0;
        int u = INT_MIN;
        int p = 1;
        int pr = 0;
        for(auto c:nums)
        {
            t*=c;
            if(c==0)
            {
                u = max(u,c);
                t = 0;
                p = 1;
                pr = 0;
                continue;
            }
           
            else if(t==0)
                t = c;
            if(t<0)
            {
                if(p==1)
                {
                    p = 0;
                    pr = t;
                    t = 0;
                    u = max(u,pr);
                }
                else
                {
                    t*=pr;
                    p=1;
                    u=max(t,u);
                }
            }
            else
                u= max(u,t);
            
        }
        reverse(nums.begin(),nums.end());
         t = 0;
        
         p = 1;
         pr = 0;
        for(auto c:nums)
        {
            t*=c;
            if(c==0)
            {
                u = max(u,c);
                t = 0;
                p = 1;
                pr = 0;
                continue;
            }
           
            else if(t==0)
                t = c;
            if(t<0)
            {
                if(p==1)
                {
                    p = 0;
                    pr = t;
                    t = 0;
                    u = max(u,pr);
                }
                else
                {
                    t*=pr;
                    p=1;
                    u=max(t,u);
                }
            }
            else
                u= max(u,t);
            
        }
     return u;   
    }
};