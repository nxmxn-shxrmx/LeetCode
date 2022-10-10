class Solution {
public:
    string breakPalindrome(string s) {
        
        if(s.size()==0 || s.size()==1)
            return "";
    
        int j = s.size()-1;
        for(int i = 0;i<s.size()/2;++i)
        {
            if('a'!=s[j])
            {
                s[i]='a';
                return s;
            }
            --j;
        }
        
        j =s.size()-1;
        s[j]='b';
        return s;
    }
};

