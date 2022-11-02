class Solution {
public:
    int maxProfit(vector<int>& v, int f) {
            int s=0;
        int u =0;
        int mi = INT_MAX;
        for(auto c:v)
        {
            if(mi>=c)
                mi =c,s+=u,u=0; 
            else
            {
                if(c-mi<u)
                {
                    s+=u;
                    mi =c;
                    u=0;
                }
                else
                u =max(u ,c-mi-f);
            }
            
        }
        return s+u;
    }
};