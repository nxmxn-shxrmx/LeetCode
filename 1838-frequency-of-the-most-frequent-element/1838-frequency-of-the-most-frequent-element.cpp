class Solution {
public:
    int check(vector<int>&v,int k)
    {
        int u =0;
        int j = v.size()-1;
        for(int i = v.size()-1;~i;--i)
        {
            if(k-(v[j]-v[i])>=0)
            {
                k-=(v[j]-v[i]);
                u = max(j-i+1,u);
            }
            else
            {
                k-=(v[j]-v[i]);
                while(j>=i && k<0)
                {
                    k +=(j-i)*(v[j]-v[j-1]);
                    j--;
                }
                  u = max(j-i+1,u);
            }
        }
        
        return u;
    }
    int maxFrequency(vector<int>& nums, int k) {
     sort(begin(nums),end(nums));
     return check(nums,k);
  
    }
};

//9 6 3
//
//13 8 5 4
//13 8 0  
//1