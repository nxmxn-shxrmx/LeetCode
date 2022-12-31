class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        if(v.size()<3)
            return 0;
        
        int d = v[0]-v[1];
        int c =0;
        int in =0;
        for(int i =1;i<v.size()-1;++i)
        {
            int p = v[i]-v[i+1];
            if(p==d)
                ++in;
            else
            {
                d = p;
                in=0;
            }
            c+=in;
                
        }
        
        return c;
    }
};