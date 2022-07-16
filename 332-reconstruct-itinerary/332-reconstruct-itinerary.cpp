class Solution {
public:
    map<string,multiset<string>>m;
    vector<string>s;
    
    void dfs(string i)
    {
        while(m[i].size())
        {
            string u = *m[i].begin();
            m[i].erase(m[i].find(u));
            dfs(u);
        }
        s.push_back(i);
    }
    vector<string> findItinerary(vector<vector<string>>& t) {
       for(auto c:t) 
           m[c[0]].insert(c[1]);
        dfs("JFK");
           reverse(s.begin(),s.end());
      return s;
    }
};