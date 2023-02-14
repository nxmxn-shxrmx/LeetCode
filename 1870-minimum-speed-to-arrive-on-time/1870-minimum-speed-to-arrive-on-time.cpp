class Solution {
public:
    bool check(int m ,vector<int>&v,double h)
    {
        double u = 0;
        for(auto c:v)
        {
            u = ceil(u);
            u +=(c*1.0/m*1.0);
            if((u-h)>0)return 0;
            
        }
        return 1;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
       int l = 0;
       int r = 1e9;
       int ans = r;
       while(l<=r) 
       {
           int m = (l+r)/2;
           if(check(m,dist,hour))
               r = m-1,ans = m;
           else
               l = m+1;
       }
     //   cout<<ans<<"\n";
        if(check(ans,dist,hour))
        return ans;
        
        return -1;
    }
};