class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(nums.back()>x && nums[0]>x)return -1;
        
        if(nums[0]==x || nums.back()==x)return 1;
        
        int ans = INT_MAX;
        
        int s1=0;
        int i  =0;
        while(i<nums.size())
        {
            if(s1+nums[i]==x)
            {
                s1+=nums[i];
                break;
            }
            else if(s1+nums[i]>x)
            {
                i--;
                break;
            }
            s1+=nums[i];
            ++i;
        }
    
        if(s1==x)ans = i+1;
        if(i==nums.size())return -1;
     //   cout<<s1<<" ";
        int j = nums.size()-1;
        while(j>=0)
        {
            if(s1+nums[j]==x)
            {
                s1 = x;
                int  p = i+1 + nums.size()-j;
                ans = min(ans,p);
                --j;
            }
            else if(s1+nums[j]>x)
            {
                if(i==-1)break;
                
                else
                    s1-=nums[i],--i;
            }
            else
           s1+=nums[j], --j;
        }
        return ans==INT_MAX?-1:ans;
    }
};