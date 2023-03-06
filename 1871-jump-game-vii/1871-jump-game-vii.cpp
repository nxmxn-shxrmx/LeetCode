class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back()=='1')return 0;
        queue<int>q;
        q.push(0);
        set<int>st;
        for(int i =minJump;i<s.size();++i)if(s[i]=='0')st.insert(i);
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            if(i==s.size()-1)return 1;
            auto it = st.lower_bound(i+minJump);
            while(it!=st.end() && (*it)<=(i+maxJump))
            {
                auto p = it;
                ++p;
                q.push(*it);
                st.erase(*it);
                it = p;
            }
        }
        return 0;
    }
};