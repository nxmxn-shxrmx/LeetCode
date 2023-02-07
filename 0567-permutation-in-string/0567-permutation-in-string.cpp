class Solution {
public:
    bool match(vector<int>&v,vector<int>&u)
    {
        for(int i = 0;i<26;++i)
            if(u[i]!=v[i])return 0;
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return 0;
        vector<int>v(26);
        vector<int>u(26);
        for(int i = 0;i<s1.size();++i)
        {
            v[s1[i]-'a']++;
            u[s2[i]-'a']++;
        }
        for(int i = 0;i<s2.size()-s1.size();++i)
        {
           if(match(u,v))return 1;
            u[s2[i+s1.size()]-'a']++;
            u[s2[i]-'a']--;
         
        }
        return match(u,v);
    }
};