class Solution {
public:
    int search(vector<int>& n, int t) {
        
        int l =0;
        int r = n.size()-1;
        
        while(l<=r)
        {
            int m =(l+r)/2;
            cout<<m<<" ";
            if(n[m]==t)
                return m;
            if(n[l]<=n[m])
            {
                if(n[l]>t || n[m]<t)
                    l =m+1;
                else r = m-1;
            }
            else
            {
                 if(n[r]<t || n[m]>t)
                     r = m-1;
                else l = m+1;
            }
            
        }
        return -1;
    }
};


    