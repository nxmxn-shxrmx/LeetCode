class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& b) {

        map<vector<vector<int>>,bool>m;
        queue<pair<pair<int,int>,vector<vector<int>>>>q;
        vector<int>a;
        int in = 0;
        int jn = 0;
        for(int i =0;i<b.size();++i)
        {
            for(int j = 0;j<b[0].size();++j)
            {    
                if(b[i][j]==0)
                {
                    in = i;
                    jn = j;
                    break;
                }
            }
            if(b[in][jn]==0)
                break;
        }
        q.push({{in,jn},b});
        int st = 0;
        int d[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty())
        {
    
            int s = q.size();
            while(s--)
            {
                
                int i = q.front().first.first;
                int j = q.front().first.second;
                vector<vector<int>>h(q.front().second.begin(),q.front().second.end());
                q.pop();
                int p = 1;
                int  t =0;
               
                for(int i =0;i<b.size();++i)
                {
                    for(int j = 0;j<3;++j)
                    {
                        if(p!=6 && p!=h[i][j])
                            t=1;
                        p++;
                    }
                }
                if(!t)
                    return st;
                
                
                if(m[h]==true)
                    continue;
                m[h]=true;
                for(auto c:d)
                {
                    int in= c[0]+i;
                    int jn =c[1]+j;
                    if(in<0 || jn<0 || in>=2 || jn>=3)
                        continue;
                    
                    swap(h[i][j],h[in][jn]);
                    q.push({{in,jn},h});
                    swap(h[i][j],h[in][jn]);
                }
                
            }
            st++;
        }
        
        return -1;
    }
};