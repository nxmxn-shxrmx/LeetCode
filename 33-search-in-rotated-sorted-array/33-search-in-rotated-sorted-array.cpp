class Solution {
public:
    int search(vector<int>& n, int t) {
        
        int l =0;
        int r = n.size()-1;
        
        while(l<=r)
        {
            int m =(l+r)/2;
            if(n[m]==t)
                return m;
            
            if(n[l]<=n[m])
            {
                if(t>n[m] || t<n[l])
                    l = m+1;
                else
                    r = m-1;
            }
            else
            {
                if(t<n[m] || t>n[r])
                    r = m-1;
                else
                    l = m+1;
            }
                
        }
        return -1;
    }
};