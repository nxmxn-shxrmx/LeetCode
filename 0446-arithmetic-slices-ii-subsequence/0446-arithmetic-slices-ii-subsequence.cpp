class Solution {
public:
   #define ll long long
    int numberOfArithmeticSlices(vector<int>& nums) {
       ll c=  0;
       vector<unordered_map<ll,ll>>v(nums.size());
       for(int i = 1;i<nums.size();++i)
       {
           for(int j =0;j<i;++j)
           {
               ll re = (long)nums[i]-(long)nums[j];
               ll o =0; 
               if(v[j].find(re)!=v[j].end())
                   o = v[j][re];
           
               v[i][re]+=o+1;
                       c+=o;
           }
       }
        return c;
    }
};