class Solution {
public:
    int partitionString(string s) {
        int c =0;
        vector<int>v(26);
        for(int i =0;i<s.size();++i)
        {
            if(v[s[i]-'a']!=0)
            {
                for(int i = 0;i<26;++i)v[i]=0;
                c++;
                v[s[i]-'a']++;
            }
            else v[s[i]-'a']++;
        }
        return c+1;
    }
};