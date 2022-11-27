class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>s;
        vector<int>v(h.size(),0);
        for(int i = 0;i<h.size();++i)
        {
            while(!s.empty() && h[s.top()-1]>=h[i])
                s.pop();
            int p =0;
            if(!s.empty())
                p = s.top();
          
            v[i] = i+1-p;
            v[i]*=h[i];
            s.push(i+1);
        }
        int u = 0;
        while(!s.empty())
            s.pop();
        
        for(int i = 0;i<h.size();++i)
        {
              while(!s.empty() && h[v.size()-s.top()]>=h[v.size()-i-1])
                s.pop();
            int p =0;
            if(!s.empty())
                p = s.top();
          
            v[v.size()-i-1] = v[v.size()-1-i]+h[v.size()-i-1]*(i+1-p);
            v[v.size()-i-1]-=h[v.size()-1-i];
            u = max(u,v[v.size()-i-1]);
            s.push(i+1);
               
        }

        return u;
    }
};