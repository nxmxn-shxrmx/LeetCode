class Solution {
public:
    map<int,bool>m;
    bool recurse(string s,string u,vector<string>w,int i)
    {
        if(i==s.size())
            return true;
        if(m.find(i)!=m.end())
            return m[i];
        for(auto c:w)
        {
            if(s.substr(i,c.size())==c)
                if(recurse(s,u,w,i+c.size()))
                    return m[i]=true;
        }
        return m[i]=false;
    }
    bool wordBreak(string s, vector<string>& w) {
        return recurse(s,"",w,0);
    }
};