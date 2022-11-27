class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
       
        map<long long,int>m;
        int c = 0;
        long long w = 0; 
        m[0]++;
        for(int i =0;i<v.size();++i)
        {
            w+=v[i];
            int d = w-k;
                c+=m[d];
            m[w]++;
        }
        return c;
    }
};