class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& s, vector<vector<int>>& q) {
        int k = 0;
        vector<int>v;
        for(auto c:s)
        if(c%2==0)
            k+=c;
        for(auto c:q)
        {
            if(s[c[1]]%2==0)
                k-=s[c[1]];
            s[c[1]]+=c[0];
            if(s[c[1]]%2==0)
                k+=s[c[1]];
            v.push_back(k);
        }
        return v;
    }
};