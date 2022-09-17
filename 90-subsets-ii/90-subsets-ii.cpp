class Solution {
public:
    void sub(vector<vector<int>>&v,vector<int>&d,int i,vector<int>&nums)
    {
        if(i==nums.size())
        {
            v.push_back(d);
        
            return;
        }
        d.push_back(nums[i]);
        sub(v,d,i+1,nums);
        d.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1])
            i+=1;
        sub(v,d,i+1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int>d;
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        sub(v,d,0,nums);
        return v;
    }
};