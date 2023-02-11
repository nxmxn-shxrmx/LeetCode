class Solution {
public:
     bool check(vector<int>&nums,int x,int k)
    {
        for(auto c:nums)
        {
            int count=(c+x-1)/x;
            k-=(count);
            if(k<0)return 0;
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
         int hi = nums.back();
        for(auto c:nums)
            hi =max(hi,c);
        int lo = 1;
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            if(check(nums,mid,h))
                hi = mid;
            else lo = mid+1;
        }
        return hi;
    }
};