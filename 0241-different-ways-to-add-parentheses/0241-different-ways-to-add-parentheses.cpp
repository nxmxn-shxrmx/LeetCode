class Solution {
public:
    map<string,vector<int>>m;
    vector<int> diffWaysToCompute(string s) {
        vector<int>ans;
        if(s.size()==0)return {};
        for(int i = 0;i<s.size();++i)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*')
            {
                
                vector<int>p;
                if(m.find(s.substr(0,i))!=m.end())
                    p = m[s.substr(0,i)];
                else
                    p =diffWaysToCompute(s.substr(0,i)),m[s.substr(0,i)]=p;
                
                vector<int>q;
                
                if(m.find(s.substr(i+1))!=m.end())
                    q = m[s.substr(i+1)];
                else
                    q =diffWaysToCompute(s.substr(i+1)),m[s.substr(i+1)]=q;
                
                
                for(auto c:p)
                {
                    for(auto x:q)
                    {
                        if(s[i]=='+')
                        {
                            ans.push_back(c+x);
                        }
                        if(s[i]=='-')
                        {
                            ans.push_back(c-x);
                        }if(s[i]=='*')
                        {
                            ans.push_back(c*x);
                        }
                    }
                }
                
            }
        }
        if(ans.size()==0)
            ans.push_back(stoi(s));
        
        return ans;
    }
};