class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string>v;
        
        if(n<=1)
            return "1";
        
        int y= k;
        string nums="";
        for(int i =0;i<n;++i)
        {
            nums+=to_string(i+1);
        }
        while(k--)
        {
    
            v.push_back(nums);
            int i = nums.size()-1;
            while(i>=1 && nums[i]<=nums[i-1])
                --i;
            if(i==0)
                break;
            int j =i;
            while(j<nums.size())
            {
                if(nums[j]<=nums[i-1])
                    break;
                ++j;
            }
            swap(nums[j-1],nums[i-1]);
            j = nums.size()-1;
            while(i<j)
            {
                swap(nums[i],nums[j]);
                --j;
                ++i;
            }
            
        }
        
        
        return v[v.size()-1];
    }
};