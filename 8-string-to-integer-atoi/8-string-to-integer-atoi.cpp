class Solution {
public:
    int myAtoi(string s) {
        
        int i=0;
        while(i<s.size() && s[i]==' ')
        {
            ++i;
        }
        long long u =0;
        bool b =0;
        if(s[i]=='+')
            ++i;
        else if(s[i]=='-')
        {
            ++i;
            b=1;
        }
         long long p = pow(2,31);
        for(i;i<s.size();++i)
        {
            if(!b && u>p-1)
            return p-1;
        
            if(b && -p>-u)
                return p;
            
            
            if(s[i]>='0' && s[i]<='9')
            {
                u = u*10+(s[i]-'0');   
            }
            else
            break;
        }
        if(b)
            u*=-1;
        
       
    // cout<<u<<" "<<p<<"\n";
        if(u>p-1)
        {
            // cout<<"y";
            return p-1;
        }
        if(-p>u)
            return -p;
        
        return u;
    }
};