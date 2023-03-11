class Solution {
public:
    vector<int>f(vector<string>v,int l,int r)
    {
        if(l==r)
            return {stoi(v[l])};
        
        vector<int>ans;
        for(int i = l;i<=r;++i)
        {
            if(v[i]=="+" || v[i]=="-" || v[i]=="*")
            {
                vector<int>p = f(v,l,i-1);
                vector<int>q = f(v,i+1,r);
                for(auto c:p)
                {
                    for(auto x:q)
                    {
                        if(v[i]=="+")
                            ans.push_back(c+x);
                        if(v[i]=="-")
                            ans.push_back(c-x);
                        if(v[i]=="*")
                            ans.push_back(c*x);
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string s) {
        vector<string>v;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='*' || s[i]=='+' || s[i]=='-')
            {
                string u= "";
                u+=s[i];
                v.push_back(u);
                continue;
            }
            string u = "";
            u+=s[i];
            if(i+1<s.size() && s[i+1]>='0' && s[i+1]<='9')
            u+=s[i+1],i+=1;
            v.push_back(u);
        }
      
        return f(v,0,v.size()-1);
    }
};