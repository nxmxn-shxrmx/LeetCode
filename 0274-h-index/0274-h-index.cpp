class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int>v(1001);
        for(auto c:citations)v[c]++;
        
        int l = 0;
        int r = citations.size();
        int ans  =0;
        while(l<=r)
        {
            int m = (l+r)/2;
            int ct = 0;
            for(int j = m;j<=1000;++j)
            {
                ct+=v[j];
                if(ct>=m)break;
            }
            
            if(ct>=m)
            {
                ans = m;
                l= m+1;
            }
            else r = m-1;
            
        }
        return ans;
    }
};