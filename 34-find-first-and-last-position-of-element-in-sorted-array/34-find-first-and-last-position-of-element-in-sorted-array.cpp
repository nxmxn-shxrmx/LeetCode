class Solution {
public:
    vector<int> searchRange(vector<int>& n, int t) {
        
        int l = 0;
        int r = n.size()-1;
        
        vector<int>v;
        while(l<=r)
        {
            int m = (l+r)/2;
            
            if(n[m]==t)
            {
                if(m==0 || n[m-1]!=t)
                {
                    v.push_back(m);
                    break;
                }
                else
                    r = m-1;
            }
            else if(n[m]>t)
                r = m-1;
            else
                l = m+1;
        }
        if(v.size()==0)
            return {-1,-1};
         l=0;
         r=n.size()-1;
         while(l<=r)
        {
            int m = (l+r)/2;
            if(n[m]==t)
            {
                if(m==n.size()-1 || n[m+1]!=t)
                {
                    v.push_back(m);
                    break;
                }
                else
                    l = m+1;
            }
            else if(n[m]>t)
                r = m-1;
            else
                l = m+1;
        }
     return v;   
    }
};