class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind =0;
        for(int i = 0;i<nums.size();++i)
        {
            int j = i;
            while(i+1<nums.size()&&nums[i]==nums[i+1])
                ++i;
            
            nums[ind++]=nums[i];
            if((i-j)>=1)nums[ind++]=nums[i];
        }
        return ind;
    }
};