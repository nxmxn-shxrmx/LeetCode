class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //1 3 4 2 2
        for(int i =0;i<nums.size();++i)
        {
            if(nums[abs(nums[i])-1]<0)
                return abs(nums[i]);
            nums[abs(nums[i])-1]*=-1;
        }
        return 0;
    }
};