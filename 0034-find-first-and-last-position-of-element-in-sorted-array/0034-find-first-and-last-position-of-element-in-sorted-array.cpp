class Solution {
public:
    int fir(vector<int>&nums,int target)
    {
        int fi = -1;
        int l = 0;
        int r = nums.size()-1;
      
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m]>target)
                r = m-1;
            else if(nums[m]==target)
                fi = m,r = m-1;
            else l++;
        }
       return  fi;
    }
      int las(vector<int>&nums,int target)
    {
        int fi = -1;
        int l = 0;
        int r = nums.size()-1;
      
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m]>target)
                r = m-1;
            else if(nums[m]==target)
                fi = m,l = m+1;
            else l++;
        }
       return  fi;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int fi =fir(nums,target);
        int la = las(nums,target);
        
       return {fi,la};
        
    }
};