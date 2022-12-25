class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        for(int i =1;i<nums.size();++i)
            nums[i]+=nums[i-1];
        for(auto c:queries)
        {
            int l =0;
            int r =nums.size()-1;
            int ans = 0;
            while(l<=r)
            {
                int m = (l+r)/2;
                if(nums[m]<=c)
                {
                    ans= m+1;
                    l= m+1;
                }
                else
                    r=m-1;
            }
            v.push_back(ans);
        }
        return v;
    }
};