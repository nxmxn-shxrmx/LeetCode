class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>>m;
        for(auto c:paths)
        {
            string d = "";
            int  i =0;
            while(i<c.size() && c[i]!=' ')
                d+=c[i++];
            d+="/";
            ++i;
            string r = "";
            for(i;i<c.size();++i)
            {
                if(c[i]=='(')
                {
                    ++i;
                    string u = "";
                    while(i<c.size()&& c[i]!=')')
                        u+=c[i++];
                    i+=1;
                    m[u].push_back(d+r);
                    r="";
                    continue;
                }
                r+=c[i];
            }
        }
        vector<vector<string>>ans;
        for(auto c:m)
        {
            if(c.second.size()>1)
                ans.push_back(c.second);
        }
        return  ans;
    }
};