class Solution {
public:
    int minJumps(vector<int>& v) {
        int n = v.size();
        unordered_map<int, vector<int>>m;
        for(int i = 0;i<n;++i)
            m[v[i]].push_back(i);
        queue<int>q;
        vector<bool>b(n);
        q.push(0);
        b[0]=1;
        int st = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int i = q.front();
                q.pop();
                if(i==n-1)return st;
                for(auto c:m[v[i]])
                    if(!b[c])b[c]=1,q.push(c);
                if((i-1)>=0 && !b[i-1])b[i-1]=1,q.push(i-1);
                 if((i+1)<n && !b[i+1])b[i+1]=1,q.push(i+1);
                m[v[i]].clear();
            }
            st++;
            
        }
        return 0;
    }
};