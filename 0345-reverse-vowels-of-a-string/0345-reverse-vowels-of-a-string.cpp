class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char,bool>m;
        m['a']=1;
        m['e']=1;
        m['i']=1;
        m['o']=1;
        m['u']=1;
        m['A']=1;
        m['E']=1;
        m['I']=1;
        m['O']=1;
        m['U']=1;
        int i = 0;
        int j = s.size()-1;
        while(i<s.size() && i<j)
        {
            if(m[s[i]])
            {
                
                while(j>=0 && !m[s[j]])
                    j--;
                swap(s[i],s[j]);
                j--;
            }
            ++i;
        }
        return s;
    }
};