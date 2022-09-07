class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int cmin=0;
        int cmax=0;
        
        int s1=INT_MAX;
        int s2=INT_MIN;
        
        int s=0;
        for(auto c:nums)
        {
            cmin+=c;
            cmax+=c;
            s1= min(s1,cmin);
            s2=max(s2,cmax);
            
            if(cmax<0)
                cmax=0;
            if(cmin>0)
                cmin=0;
            
            s+=c;
        }
        if(s==s1)
            return s2;
        
        return max(s2,s-s1);
    }
};