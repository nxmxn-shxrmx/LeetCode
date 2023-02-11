class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<=2)return 0;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i =0;i<nums.size()-2;++i)
        {
            for(int j = i+1;j<nums.size()-1;++j)
            {
                int sum = nums[i]+nums[j];
                int l = j;
                int r = nums.size()-1;
                int p = l;
                while(l<=r)
                {
                    int m = (l+r)/2;
                    if(nums[m]<sum)
                        l = m+1,p = m;
                    else 
                        r = m-1;
                }
                ans+=(p-j);
            }
        }
        return ans;
    }
};