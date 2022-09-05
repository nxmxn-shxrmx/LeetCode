class Solution {
public:
    bool vali(int x,vector<int>v,int k)
    {
        for(int i=0;i<v.size();)
        {
            if(k==0)
                return false;
            int sum=0;
            while(i<v.size() && sum+v[i]<=x)
                sum+=v[i++];
            k--;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int r=0;
        int l=0;
        for(auto c:nums)
        {
            r+=c;
            l=max(c,l);
        }
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(vali(mid,nums,m))
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        return ans;
    }
};