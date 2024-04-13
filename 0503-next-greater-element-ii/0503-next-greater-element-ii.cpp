class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& m) {
  
        int n = m.size();
        vector<int>v(n,-1);
        stack<int>s;
        for(int i = n-1;~i;--i)
        {
            
                while(!s.empty() && s.top()<=m[i])
                    s.pop();
                if(!s.empty())
                    v[i] = s.top();
            
            
            s.push(m[i]);
        }
          for(int i = n-1;~i;--i)
        {
            
                while(!s.empty() && s.top()<=m[i])
                    s.pop();
                if(!s.empty())
                    v[i] = s.top();
            
            
            s.push(m[i]);
        }
        return v;
    }
};