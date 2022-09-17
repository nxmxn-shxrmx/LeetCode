class Solution {
public:
    int findMin(vector<int>& n) {
        int l =0;
        int r = n.size()-1;
        int o = n[0];

        while(l<r)
        {
            int m = (l+r)>>1;
            
            if(n[m]>n[r])
                l = m+1;
            
            else
                r = m;
        }
        return n[l];
    }
};