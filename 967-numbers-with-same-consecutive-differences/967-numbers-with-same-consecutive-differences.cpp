class Solution {
public:
    // int c= 0;
    vector<int>v;
    void recurse(int n,int k,int p)
    {
        if(n==0)
        {
            v.push_back(p);
            return;
        }
        // int c = 0;
        for(int i=0;i<=9;++i)
        {
            int u = p%10;
            int y= abs(i-u);
            if(y==k)
            {
                recurse(n-1,k,p*10+i);   
            }
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        // int l =0;
        for(int i =1;i<=9;++i)
             recurse(n-1,k,i);
        return v;
    }
};