class Solution {
public:
    int jump(vector<int>& nums) {
        int j=0;
        int end=0;
        int fur=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            fur = max(fur,nums[i]+i);
            if(i==end)
            {
                j++;
                end =fur;
            }
        
        }
        return j;
    }
};