class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>v(1e5+1);
        int c= 0;
        for(auto x:costs)
            v[x]++;
        for(int i = 1;i<=1e5;++i)
        {
            if(coins<i)
                break;
            int p =coins/i;
            if(v[i]>=p)
                coins-=p*i,c+=p;
            else
                coins-=v[i]*i,c+=v[i];
    
        }
        return c;
    }
};