class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        if(nums.size()<=1)
            return {nums};
        
        int y= 6;
        sort(nums.begin(),nums.end());
        while(y)
        {
    
            v.push_back(nums);
            int i = nums.size()-1;
            while(i>=1 && nums[i]<=nums[i-1])
                --i;
            if(i==0)
                break;
            int j =i;
            while(j<nums.size())
            {
                if(nums[j]<=nums[i-1])
                    break;
                ++j;
            }
            swap(nums[j-1],nums[i-1]);
            j = nums.size()-1;
            while(i<j)
            {
                swap(nums[i],nums[j]);
                --j;
                ++i;
            }
            
        }
        return v;
    }
};