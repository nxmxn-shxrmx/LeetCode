class Solution {
public:
    string reverseWords(string s) {
        
        s+=" ";
        string r = "";
        string e ="";
        for(auto c:s)
        {
            if(c==' ')
            {
                if(r.size()==0)
                    r = e;
                
                else if(e.size()!=0)
                    r = e+" "+r;
                
                e = "";
            }
            else
                e+=c;
        }
        return r;
    }
};