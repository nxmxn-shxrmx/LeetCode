class Solution {
public:
    int jump(vector<int>&v) {
        int c= 0;
        int r = 0;
        int e = 0;
        for(int i = 0;i<v.size()-1;++i)
        {
            
            r = max(v[i]+i,r);
            if(e==i)
            {
                e = r;
                c++;
            }
        }
        return c;
    }
};