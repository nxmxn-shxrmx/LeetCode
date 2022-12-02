class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return 0;
        
        vector<int>v(26);
        for(auto c:word1)
            v[c-'a']++;
        vector<int>p(26);
        for(auto c:word2)
            p[c-'a']++;
        for(int i = 0;i<p.size();++i)
        {
            if(p[i]!=0 && v[i]==0)
                return 0;
            if(v[i]!=0 && p[i]==0)
                return 0;
                
        }
        sort(p.begin(),p.end());
        sort(v.begin(),v.end());
        for(int i  =0;i<26;++i)
        if(p[i]!=v[i])
            return 0;
        return 1;
    }
};