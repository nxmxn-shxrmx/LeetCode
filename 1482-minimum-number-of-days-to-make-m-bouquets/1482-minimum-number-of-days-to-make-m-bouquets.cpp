class Solution {
public:
   bool check(int mi,vector<int>&v,int m,int k)
    {
        int c = 0;
        for(auto x:v)
        {
            if(x<=mi)
            {
                c++;
                if(c==k)
                {
                    c = 0;
                    m--;
                }
            }
            else
                c = 0;
        }
        return m<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int l =1;
        int r =1e9;
        int ans = r;
        while(l<=r)
        {
            int mi= (l+r)>>1;
            if(check(mi,bloomDay,m,k))
                r = mi-1,ans = mi;
            else
                l = mi+1;
        }
        if(check(ans,bloomDay,m,k))
        return ans;
        return -1;
    }
};