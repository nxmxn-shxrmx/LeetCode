class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      
        int i = 0;
        int j =nums.size()-1;
        while(i<=j)
        {
            while(i<=j && nums[i]==val)
            {
                swap(nums[i],nums[j]);
                    --j;
            }
            ++i;
        }
        if(nums.size()==0 || nums[0]==val)return 0;
        return j+1;
    }
};