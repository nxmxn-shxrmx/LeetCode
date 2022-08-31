class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v(nums.size(),1);
        for(int i =1;i<nums.size();++i)
            v[i] = v[i-1]*nums[i-1];
        int t = nums[nums.size()-1];
        nums[nums.size()-1]=1;
        for(int i =nums.size()-2;~i;--i)
        {
            int p = nums[i];
            nums[i] = nums[i+1]*t;
            v[i]*=nums[i];
            t= p;
            
        }
        return v;
    }
};