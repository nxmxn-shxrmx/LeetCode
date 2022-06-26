class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& b) {

        map<string,bool>m;
        queue<pair<string,int>>q;
        string s ="";
        int p =0;
        int o = 0;
        for(int i =0;i<b.size();++i)
        {
            for(int j = 0;j<b[0].size();++j)
            {    
                s+=to_string(b[i][j]);
                if(b[i][j]==0)
                {
                    o=p;
                }
                p++;
            }
        }
        q.push({s,o});
        int st = 0;
        vector<vector<int>>v={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{4,2}};
        while(!q.empty())
        {
    
            int s = q.size();
            while(s--)
            {
                
                string e = q.front().first;
                int i = q.front().second;
    
                q.pop();
                if(e=="123450")
                    return st;
                
                if(m[e]==true)
                    continue;
                m[e]=true;
                for(auto c:v[i])
                {
                    swap(e[c],e[i]);
                    q.push({e,c});
                    swap(e[c],e[i]);
                }
                
            }
            st++;
        }
        
        return -1;
    }
};