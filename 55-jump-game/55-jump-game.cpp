class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        if(nums[0]==0)
            return 0;
        
        int end=0;
        int fur=0;
        for(int i=0;i<nums.size();++i)
        {
            fur = max(nums[i]+i,fur);
            if(end==i)
                end = fur;
        }
        if(end>=nums.size()-1)
            return 1;
        return 0;
    }
};