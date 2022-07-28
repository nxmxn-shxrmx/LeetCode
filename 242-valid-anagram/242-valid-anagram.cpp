class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size()!=t.size())
            return false;
        
        map<char,int>m1,m2;
        for(int i =0;i<s.size();++i)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(auto c:s)
        {
            if(m1[c]!=m2[c])
                return false;
        }
        return true;
        
    }
};