class Solution {
public:
    int mod = 1e9+7;
    int waysToSplit(vector<int>& nums) {
        vector<long long>pre(nums.size()+1);
        for(int i =1;i<=nums.size();++i)
            pre[i]+=pre[i-1]+nums[i-1];
        if(pre.back()==0)
        {
            
            long long u = pre.size();
            u = u-3;
            u = (u)*(u+1)/2;
            return u%mod;
        }
        int ans = 0;
        for(int i =1;i<pre.size()-1;++i)
        {
            int l = i+1;
            int r = pre.size()-1;
            int m1 =i+1;
            while(l<=r)
            {
                int m = (l+r)/2;
                if((pre[m]-pre[i])>=pre[i])
                    m1 = m,r = m-1;
                else l = m+1;
            }
           int u = (pre.back()-pre[i])/2;
           l = i;
           r = pre.size()-1;
           int m2=i;
           while(l<=r)
           {
               int m = (l+r)/2;
               if(pre[m]-pre[i]<=(u))l = m+1,m2 =m;
               else r = m-1;
           }
           
          
          if(pre[i]>(pre[m1]-pre[i]) || (pre[m1]-pre[i])>(pre[m2]-pre[i]))continue;
          long long int y = m2-m1+1;
          ans = ans%mod + (y)%mod;
            
        }
        return ans;
    }
};

