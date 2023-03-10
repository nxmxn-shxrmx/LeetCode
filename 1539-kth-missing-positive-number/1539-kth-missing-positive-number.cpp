class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int p = 1;
        for(auto c:arr)
        {
            while(p!=c)
            {
                k--;
                if(k==0)return p;
                p++;
            }
            p++;
        }
        k--;
        while(k--)p++;
        return p;
    }
};