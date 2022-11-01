class Solution {
public:
    bool canJump(vector<int>& v) {
        int r = v[0];
        for(int i = 1;i<v.size();++i)
        {
            if(i>r)
                return 0;
            r = max(v[i]+i,r);
        }
        return r>=v.size()-1;
    }
};