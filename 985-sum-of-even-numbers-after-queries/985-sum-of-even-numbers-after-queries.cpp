class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& s, vector<vector<int>>& q) {
         ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
                
        int k = 0;
        vector<int>v;
        for(auto c:s)
        if((c&1)==0)
            k+=c;
        for(auto c:q)
        {
            if((s[c[1]]&1)==0)
                k-=s[c[1]];
            s[c[1]]+=c[0];
            if((s[c[1]]&1)==0)
                k+=s[c[1]];
            v.push_back(k);
        }
        return v;
    }
};