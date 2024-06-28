class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>v(n);
        for(auto c:roads)
        {
            v[c[0]]++;
            v[c[1]]++;
        }
        long long sum =0;
        sort(v.rbegin(),v.rend());
        for(auto c:v)
        {
            long long y = c;
            long long k = n;
            sum+=y*k;
            n--;
        }
        return sum;
    }
};