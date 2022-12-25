class Solution {
public:
    bool check(int m,vector<int>&v,int k)
    {
        k--;
        int p =v[0];
        for(int i = 1;i<v.size();++i)
        {
            if(abs(p-v[i])>=m)
                k--,p=v[i];
            if(k==0)
                return 1;
        }
        return 0;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int l =0;
        int ans =0;
        int r =abs(price.back()-price.front());
        while(l<=r)
        {
            int m = (l+r)/2;
            if(check(m,price,k))
                l = m+1,ans= m;
            else
                r = m-1;
        }
    
        return ans;
    }
};
