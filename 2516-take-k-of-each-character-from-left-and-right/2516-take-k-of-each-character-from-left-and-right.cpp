class Solution {
public:
    bool check(int m,string s,int k)
    {
    
        int a = 0;
        int b = 0;
        int c = 0;
        int i = 0;
        int j = s.size()-1;
        while(i<m)
        {
            if(s[i]=='a')
                a++;
            if(s[i]=='b')
                b++;
            if(s[i]=='c')
                c++;
            if(a>=k && b>=k && c>=k)
                return 1;
            
            ++i;
        }
    //    cout<<i<<" "<<m<<"\n";
        --i;
        while(i!=-1 && j!=-1)
        {
             if(s[i]=='a')
                a--;
            if(s[i]=='b')
                b--;
            if(s[i]=='c')
                c--;
             if(s[j]=='a')
                a++;
            if(s[j]=='b')
                b++;
            if(s[j]=='c')
                c++;
            if(a>=k && b>=k && c>=k)
                return 1;
            --j;
            --i;
        }
     //   cout<<i<<" "<<j<<"\n";
        return 0;
        
    }
    int takeCharacters(string s, int k) {
        if(k==0)
            return 0;
        int a  = 0;
        int b = 0;
        int x = 0;
        for(auto c:s)
        {
            if(c=='a')
                a++;
            if(c=='b')
                b++;
            if(c=='c')
                x++;
        }
      
        if(a<k || b<k || x<k)
            return -1;
        int l = 0;
        int ans = s.size();
        int r = s.size();
        while((r-l)>1)
        {
            int m = (l+r)/2;
            if(check(m,s,k))
                r = m,ans=m;
            else
                l = m;
        }
        return ans;
    }
};
