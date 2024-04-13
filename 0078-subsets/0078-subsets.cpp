class Solution {
public:
    void subset(vector<vector<int>>&v,vector<int>&s,int i,vector<int>& nums)
    {
        v.push_back(s);
        for(int j = i;j<nums.size();++j)
        {
            s.push_back(nums[j]);
            subset(v,s,j+1,nums);
            s.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>v;
        vector<int>s;
        sort(nums.begin(),nums.end());
        subset(v,s,0,nums);
        return v;
        
    }
};