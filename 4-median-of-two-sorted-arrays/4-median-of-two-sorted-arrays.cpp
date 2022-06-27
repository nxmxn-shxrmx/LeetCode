class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        
        int s1 = n1.size();
        int s2 = n2.size();
        if(s1<s2)
            return findMedianSortedArrays(n2,n1);
        
        int l =0;
        int r =2*s2;
        int k = s1+s2;
        while(l<=r)
        {
            int m = (l+r)/2;
            int mx = s1+s2-m;
            
            int l1 = (mx==0)?INT_MIN:n1[(mx-1)/2];
            int l2 = (m==0)?INT_MIN:n2[(m-1)/2];
            int r1 = (mx==2*s1)?INT_MAX:n1[mx/2];
            int r2 = (m==2*s2)?INT_MAX:n2[m/2];
            
            if(l1>r2)
                l = m+1;
            else if(l2>r1)
                r = m-1;
            else 
                return ((max(l1,l2)+min(r1,r2))/2.0);
        }
        return -1;
    }
};