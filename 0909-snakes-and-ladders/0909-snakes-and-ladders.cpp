class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        vector<vector<int>>v;
        bool p = 0;
        for(int i =b.size()-1;~i;--i)
        {
            if(p)reverse(b[i].begin(),b[i].end());
            v.push_back(b[i]);
            p =!p;
        }
        int n =b.size();
        vector<int>u(n*n,INT_MAX);
        u[0]=0;
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            for(int k = i+1;k<=min(i+6,n*n-1);++k)
            {
                int p = k;
                int r = k/n;
                int c = k%n;
                if(v[r][c]!=-1)
                    p =v[r][c]-1;
                
                if(u[p]>(u[i]+1))
                    u[p]=u[i]+1,q.push(p);
            }
        }
        return u[n*n-1]==INT_MAX?-1:u[n*n-1];
    }
};