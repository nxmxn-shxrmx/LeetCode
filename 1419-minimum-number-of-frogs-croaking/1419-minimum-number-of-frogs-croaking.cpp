class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c =0;
        int r =0;
        int o = 0;
        int a = 0;
        int k = 0;
        
        for(auto x:croakOfFrogs)
        {
            if(x=='c')
            {
                k = max(k-1,0);
                c++;
            }
            if(x=='r')
            {
                if(c==0)return -1;
                c--;
                r++;
            }
            if(x=='o')
            {
                if(r==0)return -1;
                r--;
                o++;
            }
            if(x=='a')
            {
                if(o==0)return -1;
                o--;
                a++;
            }
            if(x=='k')
            {
                if(a==0)return -1;
                a--;
                k++;
            }
        }
        int s = c+r+o+a;
        return s?-1:k;
    }
};