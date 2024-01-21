class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
     m--;
     n--; 
    for(int i =nums1.size()-1;~i;--i)
    {
       if(m<0)
       {
           nums1[i] = nums2[n--];
           continue;
       }
       if(n<0)
       {
           nums1[i] = nums1[m--];
           continue;
       }
       if(nums1[m]>=nums2[n])
       {
           nums1[i]=nums1[m];
           m--;
       }
        else
        {
            nums1[i]=nums2[n];
            n--;
        }
    }
        
    }
};