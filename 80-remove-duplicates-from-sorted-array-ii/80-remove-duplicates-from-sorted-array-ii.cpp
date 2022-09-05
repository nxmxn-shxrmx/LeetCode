class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s=0;
        for(int i= 0;i<nums.size();)
        {
            int j =i;
            while(j+1<nums.size() && nums[j]==nums[j+1])
            {
                nums[j-s]=nums[j];
                ++j;
            }
            nums[j-s]=nums[j];
            j+=1;
            if((j-i-2)>=0)
                s+=j-i-2;
            i=j;
        
        }
    
        return nums.size()-s;
    }
};