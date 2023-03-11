class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int>ans;
        if(s.size()==0)return {};
        for(int i = 0;i<s.size();++i)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*')
            {
                vector<int>p = diffWaysToCompute(s.substr(0,i));
                vector<int>q = diffWaysToCompute(s.substr(i+1));
                
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