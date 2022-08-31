class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)
            return;
        
        int i =nums.size()-1;
       while(i>=1 && nums[i]<=nums[i-1])
            --i;
        if(i==0)
        {
             reverse(nums.begin(),nums.end());
            return;
        }
        
        int j=i;
        
        while(j<nums.size())
        {
            if(nums[j]<=nums[i-1])
                break;
            // cout<<nums[j]<<" ";
            ++j;
        }
        swap(nums[j-1],nums[i-1]);

        // cout<<"\n";
        reverse(nums.begin()+i,nums.end());
        
    }
};