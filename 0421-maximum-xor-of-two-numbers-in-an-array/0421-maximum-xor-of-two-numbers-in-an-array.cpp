class Solution {
public:
    class Trie 
    {
        public:
        Trie *one;
        Trie *zero;
        Trie()
        {
            one = NULL;
            zero = NULL;
        }
    };
    Trie *h = new Trie();
    void add(int n)
    {
        Trie* u = h;
        for(int i = 31;~i;--i)
        {
            if(n&(1<<i))
            {
                if(u->one==NULL)u->one = new Trie();
                u = u->one;
            }
            else
            {
                if(u->zero==NULL)u->zero = new Trie();
                u = u->zero;
            }
        }
    }
    int maxi(int n)
    {
        Trie *u = h;
        int ans = 0;
        for(int i= 31;~i;--i)
        {
            if((n&(1<<i))==0)
            {
                if(u->one)
                {
                    ans|=(1<<i);
                    u = u->one;
                }
                else
                    u = u->zero;
            }
            else
            {
                if(u->zero)
                {
                    ans|=(1<<i);
                    u = u->zero;
                }
                else u = u->one;
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
       for(auto c:nums)add(c); 
        int ans = 0;
        for(auto c:nums)ans = max(ans,maxi(c));
        return ans;
    }
};
