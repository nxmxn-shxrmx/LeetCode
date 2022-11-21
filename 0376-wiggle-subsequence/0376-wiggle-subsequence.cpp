class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
     int i = 0;
     int sum=0;
     int c = 0;
     while(i+1<nums.size() && nums[i+1]<nums[i])
    {
        ++i;
        c++;
    }
    sum+=min(1,c);
    while(i<nums.size())
    {
        c = 1;
        int j = i;
        while(i+1<nums.size() && nums[i+1]>=nums[i])
        {
            if(nums[i+1]!=nums[i])
            c++;
            ++i;
        }
        ++i;
        while(i+1<nums.size() && nums[i+1]<=nums[i])
        ++i;
    
        sum+=min(2,c);
            // cout<<sum<<" ";
        // if(sum==109)
        //     for(j;j<=i;++j)
        //         cout<<nums[j]<<" ";
        
    }
        // sum+=min(2,c);
    return sum;
}
};