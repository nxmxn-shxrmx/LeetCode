class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {

        sort(begin(v),end(v));
        
        int c= 1;
        int n = v.size();
        int p = v[0][1];
        for(int i =1;i<n;++i)
        {
            if(p>=v[i][0])
                p = min(p,v[i][1]);
            else
                p = v[i][1],c++;
        
        }
        return c;
    }
};