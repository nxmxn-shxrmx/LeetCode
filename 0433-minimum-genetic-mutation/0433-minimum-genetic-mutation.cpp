class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        q.push(start);
        multiset<string>s(bank.begin(),bank.end());
        int st =0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string u = q.front();
                q.pop();
                if(u==end)
                    return st;
                multiset<string>p;
                for(auto c:s)
                {
                       int x = 0;
                    for(int i = 0;i<u.size();++i)
                        if(u[i]!=c[i])
                            x++;
                    if(x==1)
                        q.push(c);
                    else
                        p.insert(c);
                }
                s.clear();
                s.insert(p.begin(),p.end());
             }
            st++;
        }
        return -1;
    }
};