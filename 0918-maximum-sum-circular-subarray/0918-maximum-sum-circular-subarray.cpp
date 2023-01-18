class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cmax = INT_MIN;
        int cmin = INT_MAX;
        
        int s1 =0;
        int s2 =0;
        int s = 0;
        for(auto c:nums)
        {
            s1+=c;
            s2+=c;
            cmax = max(s1,cmax);
            cmin = min(s2,cmin);
            if(s1<0)
                s1 =0;
            if(s2>0)
                s2 = 0;
            s+=c;
        }
        if(s==cmin)
            return cmax;
        return max(cmax,s-cmin);
    }
};