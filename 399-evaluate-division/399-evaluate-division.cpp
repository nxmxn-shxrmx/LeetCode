class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& values, vector<vector<string>>& qu) {
        
        map<pair<string,string>,double>m;
        map<string,vector<string>>v;
        vector<double>ans;
        for(int i =0;i<e.size();++i)
        {
            m[{e[i][0],e[i][1]}]=values[i];
            m[{e[i][1],e[i][0]}]=1/values[i];
            m[{e[i][0],e[i][0]}]=1;
            m[{e[i][1],e[i][1]}]=1;
        
            v[e[i][0]].push_back(e[i][1]);
            v[e[i][1]].push_back(e[i][0]);
        }
        
        for(auto c:qu)
        {
            queue<pair<string,double>>q;
            q.push({c[0],1.00});
            map<string,bool>b;
            while(!q.empty())
            {
                string y = q.front().first;
                double p = q.front().second;
                b[y]=true;
                if(m[{y,c[1]}]!=0)
                {
                    ans.push_back(m[{y,c[1]}]*p);
                    break;
                }
                for(auto k:v[y])
                {
                    if(!b[k])
                        q.push({k,m[{y,k}]*p});
                }
                
                 q.pop();
            }
                
                if(q.empty())
                    ans.push_back(-1.0000);
        }
        return ans;
    }
};