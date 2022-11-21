class Solution {
public:
    int calculate(string s) {
        long long num=0;
        int u  =1;
        stack<long long>v;
        for(int i = 0;i<s.size();++i)
        {
            if(s[i]==' ' || s[i]=='+')
                continue;
        
            else if(s[i]=='-')
                u=-1;
            else if(s[i]=='(')
            {
                v.push(u);
                v.push(INT_MAX);
                u =1;
            }
            else if(s[i]==')')
            {
                long long o = v.top();
                v.pop();
                v.pop();
                o = v.top()*o;
                v.pop();
                if(v.empty() || v.top()==INT_MAX)
                v.push(o);
                else
                {
                    int w = v.top();
                    v.pop();
                    v.push(w+o);
                }
            }
            else
            {
                //1 2 2 3 4 5 6
                long long p = 0;
                while(i<s.size() && s[i]-'0'>=0 && s[i]-'0'<=9)
                {
                    p = p*10 +s[i]-'0';
                    ++i;
                }
                --i;
                if(v.empty() || v.top()==INT_MAX)
                    v.push(u*p);
                else
                {
                    long long q = v.top();
                    v.pop();
                    v.push(q+u*p);
                }
                u =1;
            }
            
        }
        // cout<<"\n";
        while(!v.empty())
        {
            num+=v.top();
             cout<<v.top()<<" ";
            // cout<<v.top()<<" ";
            v.pop();
        }
        // cout<<"\n";
    return num;
    }

};