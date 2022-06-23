class Solution {
public:
    int ladderLength(string start, string end, vector<string>& w) {
        
        queue<string>q;
        q.push(start);
        multiset<string>s(w.begin(),w.end());
        map<string,bool>m;
        int st =1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string u = q.front();
                q.pop();
                if(u==end)
                    return st;
                
                for(int i = 0;i<u.size();++i)
                {
                    string p = u;
                    for(char j = 'a';j<='z';++j)
                    {
                        p[i]=j;
                        if(s.find(p)!=s.end() && !m[p])
                        {
                            q.push(p);
                            m[p]=true;
                        }
                        
                    }
                }
              
             }
            st++;
        }
        return 0;
    }
};