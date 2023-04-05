class Solution {
public:
    int partitionString(string s) {
        int c =0;
        unordered_map<char,int>m;
        for(int i =0;i<s.size();++i)
        {
            if(m[s[i]]!=0)
            {
                m.clear();
                c++;
                m[s[i]]++;
            }
            else m[s[i]]++;
        }
        return c+1;
    }
};