class Solution {
public:
    int pivot(int l,int r,vector<int>&nums)
    {
        int p = nums[l];
        int i = l;
        int j = r;
        while(i<j)
        {
            while(i<nums.size() && nums[i]<=p)
                ++i;
            while(j>=0 && nums[j]>p)
                j--;
            if(i<j)
            swap(nums[i],nums[j]);
        }
        swap(nums[l],nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size()-1;
        k = nums.size()-k;
        while(l<r)
        {
            int p = pivot(l,r,nums);
            if(k>p)
                l = p+1;
            else if(k<p)
                r = p-1;
            else break;
        }

        return nums[k];
    }
};

//1 2 5 