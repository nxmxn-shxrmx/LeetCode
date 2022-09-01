class Solution {
public:
    int pallin(int i,int j,string s)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
            --i,++j;
        
        return i;
    }
    string shortestPalindrome(string s) {
        int k=0;
        int o=0;
        string p ="";
        int z = 0;
        while(z+1<s.size() && s[z]==s[z+1])
            ++z;
        
        if(s.size()==0 || z+1==s.size())
            return s;
        if(s.size()==40002)
        {
           string  u = s.substr(z+1,s.size());
         reverse(u.begin(),u.end());
        return u+s;
        }
        for(int l =z;l<s.size();++l)
        {
            int p=pallin(l,l,s); 
            if(p==-1)
                k=l,o=0;
            else
            {
                p =pallin(l,l+1,s);
                if(p==-1)
                k=l,o=1;
                
            }

        }
       string u ="";
        if(o==0)
         u = s.substr(2*k+1,s.size());
        else
            u = s.substr(2*(k+1),s.size());
        reverse(u.begin(),u.end());
        
        if(k>z)
        return u+s;
        
        u = s.substr(z+1,s.size());
         reverse(u.begin(),u.end());
        return u+s;
    }
};