class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int>m;
        for(auto c:nums)
            m[c]++;
        int j=0;
        for(auto c:m)
        {
            for(int i=0;i<c.second;++i)
                nums[j++]=c.first;
        }
    }
};