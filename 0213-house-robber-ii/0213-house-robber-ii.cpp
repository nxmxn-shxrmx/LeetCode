class Solution {
public:
    int rob(vector<int>& n) {
        if(n.size()==1)
            return n[0];
        int a = 0;
        int b = 0;
        
        for(int i = 0;i<n.size()-1;++i)
        {
            if(i%2==0)
                a = max(a+n[i],b);
            else
                b = max(b+n[i],a);
        }
        int c = max(a,b);
        a = 0;
        b = 0;
         for(int i = 1;i<n.size();++i)
        {
            if(i%2==0)
                a = max(a+n[i],b);
            else
                b = max(b+n[i],a);
        }
        int d = max(a,b);
        return max(c,d);
    }
};