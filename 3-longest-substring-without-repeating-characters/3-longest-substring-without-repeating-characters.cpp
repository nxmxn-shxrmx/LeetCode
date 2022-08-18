class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char>st;
        int t =0;
        int j=  0;
        for(auto c:s)
        {
            while(st.find(c)!=st.end())
            {
                st.erase(s[j]);
                ++j;
            }
            st.insert(c);
            int y= st.size();
            t = max(y,t);
        }
        return t;
    }
};