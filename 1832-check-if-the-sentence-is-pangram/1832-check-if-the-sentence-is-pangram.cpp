class Solution {
public:
    bool checkIfPangram(string s) {
       long long u = 67108863;
        long long k = 0;
        for(auto c:s)
        {
            k|=(1<<(c-'a'));
        }
        return k==u;
    }
};