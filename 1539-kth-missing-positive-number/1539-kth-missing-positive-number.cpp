class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int p = 1;
        for(auto c:arr)
        {
            if(p-c==0)p++;
            else
            {
                if((c-p)<k)
                    k-=(c-p);
                else
                    return p+k-1;
                
                p =c+1;
            }
            
        }
        p+=k-1;
        return p;
    }
};