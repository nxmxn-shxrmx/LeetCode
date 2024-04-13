class Solution {
public:
    
    void subset(vector<vector<int>>&v,vector<int>&s,int i,vector<int>& nums)
    {
        v.push_back(s);
        for(int j = i;j<nums.size();++j)
        {
            if(j>i&&nums[j-1]==nums[j])continue;
            s.push_back(nums[j]);
            subset(v,s,j+1,nums);
            s.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int>d;
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        subset(v,d,0,nums);
        return v;
    }
};