class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<int>in(n);
        vector<vector<int>>out(n);
        
        for(auto c:p)
        {
            in[c[0]]++;
            out[c[1]].push_back(c[0]);
        }
        queue<int>q;
        for(int i = 0;i<n;++i)
        {
            if(in[i]==0)
                q.push(i);
        }
        int a = 0;
        while(!q.empty())
        {
            int i = q.front();
            a++;
            q.pop();
            for(auto c:out[i])
            {
                in[c]--;
                if(in[c]==0)
                    q.push(c);
            }
        }
        if(a==n)
            return true;
        return 0;
        
    }
};