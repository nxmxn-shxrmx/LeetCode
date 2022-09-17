class Solution {
public:
    void subset(vector<vector<int>>&v,vector<int>&s,int i,vector<int>& nums)
    {
        if(i==nums.size())
        {
            v.push_back(s);
            return;
        }
        
        s.push_back(nums[i]);
        subset(v,s,i+1,nums);
        s.pop_back();
        subset(v,s,i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>v;
        vector<int>s;
        subset(v,s,0,nums);
        return v;
        
    }
};