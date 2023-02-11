class Solution {
public:
    bool check(vector<int>&nums,int x,int k)
    {
        for(auto c:nums)
        {
            int count=(c+x-1)/x;
            k-=(count-1);
            if(k<0)return 0;
        }
        return 1;
    }
    int minimumSize(vector<int>& nums, int maxOper) {
        sort(nums.begin(),nums.end());
        int lo = 1;
        int hi = nums.back();
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            if(check(nums,mid,maxOper))
                hi = mid;
            else lo = mid+1;
        }
        return hi;
    }
};