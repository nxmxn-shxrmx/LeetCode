class Solution {
public:
    bool canConstruct(string a, string b) {
        
        if(a.size()>b.size())
            return false;
        
        map<char,int>m1,m2;
        
        for(int i =0;i<b.size();++i)
        {
            if(i<a.size())
                m1[a[i]]++;
            m2[b[i]]++;
        }
        for(auto c:a)
        {
            if(m1[c]>m2[c])
                return false;
        }
        return true;
        
            
        
    }
};