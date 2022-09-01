class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
      
        
        vector<vector<int>>v;
        sort(in.begin(),in.end());
        v.push_back(in[0]);
        
        for(int i = 1;i<in.size();++i)
        {
            if(v[v.size()-1][1]>=in[i][0])
                v[v.size()-1][1] = max(v[v.size()-1][1],in[i][1]);
            else
                v.push_back(in[i]);
        }
        return v;
    }
};