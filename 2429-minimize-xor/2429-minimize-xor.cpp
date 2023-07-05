class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ca = 0;
        int cb = 0;
        vector<int>v(32);
        for(int i= 0;i<32;++i)
        {
            if(num1&(1<<i))ca++;
            if(num2&(1<<i))cb++;
        }
        int ans =0;
        for(int i =31;~i&&cb;--i)
        {
            if(num1&(1<<i))
            {
                cb--;
                ans|=(1<<i);
                v[i]=1;
            }
        }
        int i =0;
        while(cb)
        {
            if(v[i])
            {++i;
             continue;
            }
            ans|=(1<<i);
            ++i;
            cb--;

        }
        return ans;
    }
};

