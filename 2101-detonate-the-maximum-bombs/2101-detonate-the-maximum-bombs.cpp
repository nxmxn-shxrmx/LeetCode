class Solution {
public:
    vector<vector<int>>v;
    vector<bool>bol;
    long long  c=0;
    void dfs(int i)
    {
        bol[i]=true;
        c++;
        // cout<<i<<" ";
        for(auto c:v[i])
        {
            if(!bol[c])
                dfs(c);
        }
    }
    int maximumDetonation(vector<vector<int>>& b) {
        v = vector<vector<int>>(b.size());
       
        for(int i =0;i<v.size();++i)
        {
            for(int j =i+1;j<v.size();++j)
            {
                long long x1 = pow((b[i][0]-b[j][0]),2)+.25;
                long long x2 = pow((b[i][1]-b[j][1]),2)+.25;
                
                long long g = ceil(sqrt(x1+x2));
                if(g<=b[i][2])
                    v[i].push_back(j);
                if(g<=b[j][2])
                    v[j].push_back(i); 
            }
        }
        
        long long k =0;
        for(int i=0;i<v.size();++i)
        {
             bol = vector<bool>(b.size());
                dfs(i),k = max(k,c),c=0;
        }
    
        return k;
    }
};