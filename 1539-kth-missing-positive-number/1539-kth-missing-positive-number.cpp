class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int p  = 1;
        for(auto c:arr)
        {
            if(p-c==0)p++;
            else
            {
                if(p+k<=c)return p+k-1;
                
                k-=(c-p);
                p = c+1;
            }
        }
        
        return p+k-1;
    }
};