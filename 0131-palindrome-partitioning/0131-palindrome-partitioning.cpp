class Solution {
public:
    vector<vector<string>>v;
    void f(string s,int i,vector<string>&g)
    {
        if(i==s.size())
        {
            if(g.size()==0)return;
        string p = g.back();
        int j = 0;
        int k = p.size()-1;
        while(j<p.size()/2 && p[j]==p[k])
            ++j,--k;
        if(j==p.size()/2)
            v.push_back(g);
            return;
        }
        if(g.size()==0)
        {
            string u ="";
            u+=s[i];
            g.push_back(u);
            f(s,i+1,g);
            g.pop_back();
            return;
        }
        string u =g.back();
        u+=s[i];
        string p = g.back();
        g.pop_back();
        g.push_back(u);
        f(s,i+1,g);
        g.pop_back();
        g.push_back(p);
        int j = 0;
        int k = p.size()-1;
        
        while(j<p.size()/2 && p[j]==p[k])
            ++j,--k;
        if(j==p.size()/2)
        {
            u = "";
            u+=s[i];
            g.push_back(u);
            f(s,i+1,g);
            g.pop_back();
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>g;
        f(s,0,g);
        return v;
    }
};