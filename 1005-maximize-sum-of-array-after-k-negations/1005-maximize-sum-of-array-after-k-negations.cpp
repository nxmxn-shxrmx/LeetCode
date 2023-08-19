class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        vector<int>v(201);
        for(auto c:nums)
        {
            int x = abs(c);
            if(c<0)
            {
                x+=100;
            }
            v[x]++;
        }
        int las = INT_MAX;

        int sum=0;
        for(int i = v.size()-1;~i;--i)
        {
           
            if(v[i])
            {
                if(i>100)
                {
                     if(k>v[i])
                     {
                         k-=v[i];
                         int p =i;
                            p-=100;
                        sum+=v[i]*(p);
                         if((i-100)<las)
                             las = i-100;
                     }
                     else
                     {
                         sum+=k*(i-100);
                         v[i]-=k;
                         k =0;
                         sum+=v[i]*(100-i);
                      }
                }
                else
                {
                    sum+=v[i]*i;
                    if(i<las)
                        las = i;
                }
                cout<<sum<<" ";
            }
        }
        
        
            if(k%2)sum-=2*las;
        
        return sum;
    }
};