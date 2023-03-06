class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back()=='1')return 0;
        queue<int>q;
        q.push(0);
        int l = 0;
        int r = 0;
        while(!q.empty())
        {
            int i = q.front();
           // cout<<i<<"\n";
            q.pop();
            if(i==s.size()-1)return 1;
            l = max(i+minJump,r+1);
            int n =s.size()-1;
            for(int j = l;j<=min(i+maxJump,n);++j)
                if(s[j]=='0')q.push(j);
            r = i+maxJump;
        }
        return 0;
    }
};