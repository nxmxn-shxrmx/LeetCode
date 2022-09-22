class Solution {
public:
    string reverseWords(string s) {
        s = " "+s;
        string ans = "";
        string r ="";
        for(int i =s.size()-1;~i;--i)
        {
            if(s[i]==' ')
            {
                if(ans.size()!=0)
                ans = r + " " + ans;
                else
                    ans = r;
                r= "";
            }
            else
                r+=s[i];
        }
        return ans;
    }
};