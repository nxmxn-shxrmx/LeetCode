class Solution {
public:
    void reverse(int i,int j,vector<int>&v)
    {
        while(i<j)
        {
            swap(v[i],v[j]);
            --j;
            ++i;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
         reverse(0,nums.size()-1,nums);
        reverse(0,k-1,nums);
        reverse(k,nums.size()-1,nums);
      
    }
};
    