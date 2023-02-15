class Solution {
public:
    int mod = 1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long  ans =0;
        long long u = LLONG_MAX;
        vector<int>p;
        for(int i=0;i<nums1.size();++i)
            ans +=  abs(nums1[i]-nums2[i]),p.push_back(nums1[i]);
        sort(p.begin(),p.end());
        for(int i = 0;i<nums1.size();++i)
        {
            long long q = ans-abs(nums2[i]-nums1[i]);
            int l = 0;
            int w = INT_MAX;
            int r = nums2.size()-1;
            
            while(l<=r)
            {
                int m = (l+r)/2;
                int t =abs(nums2[i]-p[m]);
                w = min(w,t);
                if(p[m]<=nums2[i])
                    l = m+1;
                else 
                    r = m-1;
            }
            q = q + w;
            u = min(u,q);
        }
       return u%mod;
    }
};

// 1 2 4 4 7 10 