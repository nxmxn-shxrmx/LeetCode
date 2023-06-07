class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ct = 0;
        for(int i= 0;i<=29;++i)
        {
            int p =(1<<i)&a?1:0;
            int q = (1<<i)&b?1:0;
            int r = (1<<i)&c?1:0;
            
          //  cout<<p<<" "<<q<<" "<<r<<"\n";
            if(r)
            {
                if(p==0&&q==0)ct++;
            }
            else
            {
               // cout<<"hello\n";
                if(p)ct++;
                if(q)ct++;
            }
          //  cout<<ct<<"\n";   
        }
        return ct;
    }
};