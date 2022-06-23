class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string,bool>m;
        for(auto c:deadends)
            m[c]=true;
        
        queue<string>q;
        
        if(!m["0000"])
        q.push("0000"),m["0000"]=true;
        
        int st = 0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {    
                string s = q.front();
                q.pop();
                if(s==target)
                    return st;
                set<string>p;
                for(int i = 0;i<4;++i)
                {
                    char r = s[i];
                    if(r=='9')
                    {
                        s[i] = r-1;
                        p.insert(s);
                        s[i]='0';
                        p.insert(s);
                    } 
                    else if(r=='0')
                    {
                        s[i]=r+1;
                        p.insert(s);
                        s[i]='9';
                        p.insert(s);
                    }
                    else
                    {
                        s[i]=s[i]+1;
                        p.insert(s);
                        s[i]=s[i]-2;
                        p.insert(s);
                    }
                    s[i]=r;
                }
                for(auto c:p)
                {
                    if(!m[c])
                    {
                        m[c]=true;
                        q.push(c);
                    }
                }
                
            }
            st++;
        }
        return -1;
    }
};