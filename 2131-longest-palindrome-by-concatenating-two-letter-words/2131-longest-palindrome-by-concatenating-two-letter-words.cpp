class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        int u = 0;
        map<string,int>m;
        map<string,int>g;
     for(auto c:w)
     {
         string s ="";
         s+=c[1];
         s+=c[0];
         if(c[0]==c[1])
         {
            g[c]++;  
            continue;
         }
         if(m[s]==0)
                m[c]++;
         else
         {
             u+=4;
             m[s]--;
         }
     }

        int o = 0;
        for(auto c:g)
        {
            if(c.second%2)
            {
                if(c.second>o)
                {
                    if(o!=0)
                        o--;
                    u+=2*o; 
                   o= c.second;
                }
                else
                {
                    u+=2*c.second; 
                    u-=2;
                }
            }
            else
            {
                u+=2*c.second;
            }
        }
        return u+2*o;
    }
};