class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int u = __gcd(s1.size(),s2.size());
        if(s1.size()<s2.size())swap(s1,s2);
        bool yes=0;
        string ans = "";
        for(int j = 0;j<s1.size();j+=u)
        {
            int o = 0;
            int x =j;
            int y =j;
            if(y>=s2.size())y = 0;
            while(o<u)
            {
                if(ans.size()!=u)
                    ans+=s1[x];
                if(s1[x]==s2[y] && s1[x]==s1[o])
                    ++x,++y,++o;
                else
                {
                    yes=1;
                    break;
                }
            }
            if(yes)
            break;
        }
        if(!yes)
            return ans;

        
        return "";
    }
};