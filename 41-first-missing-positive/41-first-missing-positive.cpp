class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i =0;i<nums.size();++i)
        {
            if(nums[i]>0 && nums[i]<=nums.size())
            {
                nums[i]*=-1;
            }
            else
                nums[i]=-999999;
            
        }
     
      // for(auto c:nums)
      //     cout<<c<<" ";
        for(int i=0;i<nums.size();++i)
        {
            if(abs(nums[i])<=nums.size())
            {
                nums[abs(nums[i])-1]=abs(nums[abs(nums[i])-1]);
            }
        }
        int j=1;
       // for(auto c:nums)
       //    cout<<c<<" ";
        for(int i =0;i<nums.size();++i)
        {
            if(nums[i]<0)
                return j;
            j++;
        }
    
        return j;
    }
};