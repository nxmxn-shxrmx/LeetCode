class Solution {
public:
    int hIndex(vector<int>& citations) {
      
        sort(citations.begin(),citations.end());
        int l = 0;
        int r = citations.size()-1;
        int ans  =0;
        while(l<=r)
        {
            int m = (l+r)/2;
            
            if(citations[m]>=(citations.size()-m))
            {
                ans = citations.size()-m;
                r= m-1;
            }
            else l = m+1;
            
        }
        return ans;
    }
};