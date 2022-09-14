class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int m = 0;
        int j =0;
        int f= 0;
    for(int i = 0;i<size(nums);++i)
    {
        if(nums[i]==0)
            f++;
        while(j<size(nums) && f>k)
        {
            if(nums[j]==0)
                f--;
            ++j;
        }
        m = max(i-j+1,m);
            
    }
        return m;
    }
};