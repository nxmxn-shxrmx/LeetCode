class Solution {
public:
    string ans="99999999999999";
    void f(int i,string t,string p,vector<int>v)
    {
        if(i==p.size())
        {
            if(ans>t)
                ans = t;
            return;
        }
        
        if(p[i]=='I')
        {
            for(int j = t[t.size()-1]-'0' +1 ;j<=9;++j)
            {
                if(!v[j])
                {
                    v[j]=1;
                    f(i+1,t+to_string(j),p,v);
                    v[j]=0;
                }
            }
        }
        else
        {
            for(int j = t[t.size()-1]-'0'-1;j>=1;--j)
            {
                if(!v[j])
                {
                    v[j]=1;
                    f(i+1,t+to_string(j),p,v);
                    v[j]=0;
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        vector<int>v(10);
        for(int i = 1;i<10;++i)
        {
            v[i]=1;
            f(0,""+to_string(i),pattern,v);
            v[i]=0;
        }
        return ans;
    }
};